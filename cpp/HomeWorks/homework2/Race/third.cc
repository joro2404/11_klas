#include "third.hh"
#include "racer.hh"

void third::move(std::vector< std::vector < Racer* > > race, std::vector <std::string> positions){


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

        if(x == 0){
            race[x][y] = NULL;
            exit;
        }

        for (int i = 0; i <= speed; i++){
            if(y+i >= race[x].size()){
                positions.push_back(name);
                check++;
                race[x][y] = NULL;
                break;
            }
            if(race[x-1][y+i] != NULL){
                race[x-1][y+i] = NULL;
                race[x][y] = NULL;
                check ++;
                break;
            }
        }

        if(check == 0){
            race[x+1][y+speed] =  race[x][y];
            race[x][y] = NULL;
        }
    }

    else{
        finished++;
    }

     
}

third::third(std::string name, int position, int speed): Racer(name, position, speed){}