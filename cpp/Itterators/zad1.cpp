#include <iostream>
#include <queue>
#include <string>

using namespace std;

namespace brackets {
    class Brackets {

        string s;
        char last;
        queue<char> my_queue;

        public :

        void Read(){

            getline(cin, s);
        }

        void pushBracketsInQueue(){

            for(int i=0;i<s.length();i++){

                if(s[i] == '(' || s[i] == ')'){

                    my_queue.push(s[i]);
                    //last = s[i];

                }
            }
        }

        int checkBrackets(){

            int checker = 0;

            while(!my_queue.empty()){

                if(my_queue.front() == '(')checker++;
                if(my_queue.front() == ')')checker--;;
                my_queue.pop();
                if(checker < 0)return 0;
            }

            return 1;
        }

        int countBrackets(){

            Read();
            pushBracketsInQueue();

            int checker = 0;

            while(!my_queue.empty()){

                if(my_queue.front() == '(')checker++;
                if(my_queue.front() == ')')checker--;
                my_queue.pop();
                if(checker < 0)return 0;

            }

            if(checker == 0){

                return 1;
            }
            
            return 0;
        }

    };
}