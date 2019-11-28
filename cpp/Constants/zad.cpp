#include <iostream>
#include <string>
#include <vector>
using namespace std;

class InvalidKindAnimal{

    string message;

    public:

        InvalidKindAnimal(string message){
            this->message = message;
        }

        string what(){
            return message;
        }
};

class Animal{
    int age;
    const string name;

    public:

        Animal(int age, const string name): name(name){
            this->age = age;
        }

        int getAge(){
            return age;
        }

        string getName(){
            return name;
        }
};

class Cat: public Animal {
    public:
        Cat(int age, const string name):Animal(age, name){}
};

class Dog: public Animal {
    public:
        Dog(int age, const string name):Animal(age, name){}
};


class Shelter{

    static vector<Animal> animals;
    Shelter(){}

    public:

        static void addAnimal(string kind, string name, int age){
            if(kind == "dog"){
                animals.push_back(Dog(age, name));
            }
            else if(kind == "cat"){
                animals.push_back(Cat(age, name));
            }

            else{
                throw InvalidKindAnimal("You have entered invalid kind of animal! ");
            }
        }

        static void printShelter(){
            for (int i = 0; i < animals.size(); i++){
                cout << animals[i].getName() << endl;
            }
            
        }
};

vector<Animal> Shelter::animals = {};

int main(){

    Shelter::addAnimal("dog", "Rony", 2);
    Shelter::addAnimal("cat", "Suzi", 4);
    Shelter::printShelter();
}