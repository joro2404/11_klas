#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class OneException {

    string message;

    public : 

        OneException(string message){

            this->message = message;
        }

        string what(){

            return message;
        }

};

class CarCatalogue {

    string producer;
    vector<string> models;

    public:

        CarCatalogue() {}

        CarCatalogue(string producer, vector<string> models) {

            this->producer = producer;
            this->models = models;

            if(models.size() < 5)throw OneException("You must have atleast 5 models! ");
            if(producer.length() < 5)throw OneException("Yor producer's name must be atleast 5 charecters long! ");

            for(int i=0;i<models.size();i++){
                if(models[i] == "")throw OneException("You must have something in the name of the model! ");

                for(int j=0;j<models.size();j++){
                    if(models[j] == models[i] && j != i)throw OneException("You must have different models! ");
                }
            }
        }

        string getBrand() {

            return producer;
        }

        vector<string> getModels(){

            return models;
        }

        void addModel(string model_name){

            if(model_name == "")throw OneException("You must have something in the name of the model! ");
            for(int i=0;i<models.size();i++){

                if(models[i] == model_name)throw OneException("You must have different models! ");
            }
            models.push_back(model_name);
        }

        int hasModel(string model_name){

            for(int i=0;i<models.size();i++){

                if(models[i] == model_name)return 1;
            }
            
            return 0;
        }

        string toString() {

            ostringstream out;
            out << producer << ": " << "\n  ";

            for(int i=0;i<models.size();i++){

                out << models[i] << "\n  ";
            }
                
            string data = out.str();

            return data;
        }

        void removeModelAt(int index) {
            
            if(index >= models.size()-1)throw OneException("There is no such index! ");
            models.erase(models.begin()+index);
        }

        void replaceModelAt(int index, string model_name){

            if(index >= models.size()-1)throw OneException("There is no such index! ");

            if(model_name == "")throw OneException("You must have something in the name of the model! ");

            for(int i=0;i<models.size();i++){

                if(models[i] == model_name)throw OneException("You must have different models! ");
            }
            
            replace(models.begin(), models.end(), models[index], model_name);
        }
};

int main() {

    vector<string> models;
    string help;
    int number_of_models = 5;
    string name = "vank0";

    for(int i=0;i<number_of_models;i++){

        getline(cin, help);
        models.push_back(help);
    }

    try{
        CarCatalogue CarCatalogue("BMVdf", models);
        string data = CarCatalogue.toString();
        cout << data<< endl;
        CarCatalogue.addModel(name);

    }catch(OneException ex){

        cout << ex.what() << endl;
    }

}