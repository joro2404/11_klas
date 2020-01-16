#include "first.hh"
#include "racer.hh"
#include <iostream>
using namespace std;

void first::move(std::vector< std::vector < Racer* > > race, std::vector <std::string> positions){

    int finished = 0;

    for (int i = 0; i < positions.size(); i++){
        if(positions[i] == name)finished++;
    }

    if(finished == 0){
        // cout << "test" << endl;
        int x = 0;
        int y = 0;
        int check = 0;
        int idk = 0;

        for (int i = 0; i < race.size(); i++){
            for (int j = 0; j < race[i].size(); j++){
                if(race[i][j]->name == name){
                    x = i;
                    y = j;
                    idk++;
                    break;
                }
            }
            if(idk > 0 )break;
        }
        
        // cout << race[x].size() << endl;
        for (int i = 0; i <= speed; i++){
            if(y+i >= race[x].size()){
                positions.push_back(name);
                race[x][y] = NULL;
                check++;
                break;
            }
            // cout << race[x].size() << endl;
            if(race[x][y+i] != NULL){
                race[x][y+i] = NULL;
                race[x][y] = NULL;
                check ++;
                break;
            }
        }

        cout << race[x].size() << endl;
        cout << y+speed << endl;
        if(check == 0){
            cout << y+speed << endl;
            race[x][y+speed] =  race[x][y];
            race[x][y] = NULL;
        } 
        cout << y+speed << endl;
    }

    else{
        finished++;
    }
}

first::first(std::string name, int position, int speed): Racer(name, position, speed){}