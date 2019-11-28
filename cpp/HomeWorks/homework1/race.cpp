#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

class Contestant {

    string name;
    double speed;
    double distance;

    public:

        Contestant(){}

        Contestant(string name, double speed){

            this->name = name;
            this->speed = speed;
            this->distance = 0;
        }

        string getName(){

            return name;
        }

        double getSpeed(){

            return speed;
        }

        double getDistance(){

            return distance;
        }

        double calcDistance(int iteration_count){

            distance = speed * iteration_count;
            return distance;
        }
};

class Race {

    vector<Contestant> contestants;

    public:

        Race(){}

        Race(vector<Contestant> contestants){

            this->contestants = contestants;
        }

        vector<Contestant> getContestants(){

            return contestants;
        }

        void addContestant(Contestant new_contestant){
            
            contestants.push_back(new_contestant);
        }

        void resetContestants(){

            for(int i=0;i<contestants.size();i++){
                
                contestants[i].calcDistance(0);
            }
        }

        vector<Contestant> simulateRace(int iteration_count){

            vector<double> dist;
            vector<Contestant> sorted;

            resetContestants();

            for(int i=0;i<contestants.size();i++){

                contestants[i].calcDistance(iteration_count);

                //if(i == 0 || dist[i-1].getDistance < contestants[i].getDistance )dist.push_back(contestants[i]);
            }

            for(int i=0;i<contestants.size();i++){

                dist[i] = contestants[i].getDistance();
            }

            sort(dist.begin(), dist.end());

            for(int i=0;i<dist.size();i++){

                for(int j=0;j<contestants.size();j++){
                    
                    if(dist[i] == contestants[j].getDistance())sorted.push_back(contestants[j]);
                }
            }

            return sorted;
        }

        string getContestantStanding() {

            int iteration_count = 5;            
            vector<Contestant> sorted = simulateRace(iteration_count);

            ostringstream out;


            for(int i=0;i<sorted.size();i++){

                out << sorted[i].getName() << ": " << sorted[i].getDistance() << '(' << sorted[i].getSpeed() << " km/h)\n";
            }
                
            string data = out.str();

            return data;
        }
};

int main() {

    return 0;
}