#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class OneException{

    string message;

    public:

        OneException(string message) {
            this->message = message;
        }

        string what() {
            return message;
        }
};

class CarCatalog{

    string name;
    vector<string> models;

    public:

        CarCatalog() {}

        CarCatalog(string name, vector<string> models) {
            this->name = name;
            this->models = models;

            if(name.length() < 5) throw OneException("You need to have more than 5 characters for produer! \n");
        }

        string getBrand() {
            return name;
        }

        vector<string> getModels(){
            return models;
        }

        void addModels(string model_name){
            models.push_back(model_name);
        }

        int hasModel(string model_name){

            for(int i=0;i<models.size();i++){
                if(models[i] == model_name)return 1; 
            }

            return 0;
        }


};

int main() {

    vector<string> models = {"asdsad", "asdasd"};

    try{
        CarCatalog CarCatalog("BMV", models);

    }catch(OneException ex){
        cout << ex.what() << endl;
    }

    cout << "kur" << endl;
}