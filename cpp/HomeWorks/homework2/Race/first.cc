#include "first.hh"
#include "racer.hh"

void first::move(std::vector< std::vector < Racer* > > race, std::vector <std::string> positions){

    int finished = 0;

    for (int i = 0; i < positions.size(); i++){
        if(positions[i] == name)finished++;
    }

    if(finished == 0){

        int x, y, check;
        for (int i = 0; i < race.size(); i++){
            for (int j = 0; j < race[i].size(); j++){
                if(race[i][j]->name == name){
                    x = i;
                    y = j;
                }
            }
        }
        
        for (int i = 0; i <= speed; i++){
            if(y+i >= race[x].size()){
                positions.push_back(name);
                race[x][y] = NULL;
                check++;
                break;
            }

            if(race[x][y+i] != NULL){
                race[x][y+i] = NULL;
                race[x][y] = NULL;
                check ++;
                break;
            }
        }

        if(check == 0){
            race[x][y+speed] =  race[x][y];
            race[x][y] = NULL;
        }  
    }

    else{
        finished++;
    }
}

first::first(std::string name, int position, int speed): Racer(name, position, speed){}