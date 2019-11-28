#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class OneException {

    string message;

    public:

        OneException(string message){

            this->message = message;
        }

        string what(){

            return message;
        }
};

class StudentInfo {

    string name;
    vector<double> marks;

    public:

        StudentInfo(){}

        StudentInfo(string name, vector<double> marks){

            this->name = name;
            this->marks = marks;

            if(marks.size() > 10)throw OneException("marks could not be more than 10! ");
            if(name.length() < 5)throw OneException("Student name must be more than 5 chars! ");

            for(int i=0;i<marks.size();i++){

                if(marks[i] < 2 || marks[i] > 6)throw OneException("marks could only be from 2 to 6!");
            }
        }

        string getName(){

            return name;
        }

        vector<double> getMarks(){

            return marks;
        }

        void addMark(double new_mark){

            if(marks.size() > 10)throw OneException("marks could not be more than 10! ");
            if(new_mark < 2 || new_mark > 6)throw OneException("marks could only be from 2 to 6!");
            
            marks.push_back(new_mark);
        }

        double getAverage(){

            double average;

            for(int i=0;i<marks.size();i++){
                
                average += marks[i];
            }

            return average/marks.size();
        }

        string toString() {

            ostringstream out;
            out << name << ": ";

            for(int i=0;i<marks.size();i++){

                out << marks[i] << " ";
            }

            out << "\naverage: " << getAverage();
                
            string data = out.str();
            
            return data;
        }


};

int main() {

    vector<double> marks = {2.5, 3.5, 6, 6, 5};

    class StudentInfo stu("Bopkata", marks);

    
    try{
        stu.addMark(1);
    }catch(OneException ex){
        cout << ex.what() << endl;
    }
    cout << stu.toString() << endl;

    vector<double> m = stu.getMarks();
    for(int i=0;i<m.size();i++){
        printf("%f\n", m[i]);
    }
    return 1;
}