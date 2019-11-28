from flask import Flask
from flask import render_template, redirect, url_for, request
from post import Post
import sqlite3

app = Flask(__name__)           

conn = sqlite3.connect('example.db')


conn.cursor().execute('CREATE TABLE IF NOT EXISTS posts(id  INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, author TEXT, content TEXT)')
conn.commit()


@app.route("/")
def hello():               
    return redirect(url_for('list_posts'))

@app.route('/posts')
def list_posts():
    conn = sqlite3.connect('example.db')
    rows = conn.cursor().execute('SELECT * FROM posts').fetchall()
    posts = [Post(*row) for row in rows]
    return render_template('posts.html', posts = posts)

@app.route('/posts/<int:id>')
def show_post(id):
    post = Post.find(id)
    return render_template('post.html', post=post)

@app.route('/posts/new', methods = ['GET', 'POST'])
def new_post():
    if request.method == 'GET':
        return render_template('new_post.html')
    elif request.method == 'POST':
        values = (None, request.form['name'], request.form['author'], request.form['content'])
        Post(*values).create()
        return redirect(url_for('list_posts'))
