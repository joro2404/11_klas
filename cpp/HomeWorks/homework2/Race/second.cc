#include "second.hh"
#include "racer.hh"

void second::move(std::vector< std::vector < Racer* > > race, std::vector <std::string> positions){

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

        if(y+1 > race[x].size()){
            positions.push_back(name);
            exit;
        }

        if(x+1 > race.size()){
            race[x][y] = NULL;
            check ++;
        }
        else if (y+1 > race[x].size()){
            race[x][y] = NULL;
            check++;
        }

        else if(race[x+1][y+1] != NULL){
            check++;
            race[x+1][y+1] = NULL;
            race[x][y] = NULL;
        }

        else if(race[x+1][y] != NULL){
            check++;
            race[x+1][y] = NULL;
            race[x][y] = NULL;
        }

        else if(race[x][y+1] != NULL){
            check++;
            race[x][y+1] = NULL;
            race[x][y] = NULL;
        }

        for (int i = 0; i <= speed; i++){
            if(y+1+i >= race[x].size()){
                positions.push_back(name);
                check++;
                race[x][y] = NULL;
                break;
            }
            if(race[x][y+1+i] != NULL){
                race[x][y+1+i] = NULL;
                race[x][y] = NULL;
                check ++;
                break;
            }
        }

        if(check == 0){
            race[x][y+1+speed] =  race[x][y];
            race[x][y] = NULL;
        }
    }

    else{
        finished++;
    }

}

second::second(std::string name, int position, int speed): Racer(name, position, speed){}