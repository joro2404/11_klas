#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include<algorithm>
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
		
		double getSpeed() {
		
			return speed;
		}
		
		double getDistance() {
		
			return distance;
		}
		
		double calcDistance(int iterations_count) {
		
			distance = speed * iterations_count;
			return distance;
		}
		
		
};
/*
bool compareContestants(Contestant contestant1, Contestant contestant2) {

	return contestant1.getDistance() > contestant2.getDistance();
}
*/
class Race{

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
		
		string simulateRace(int iterations_count){
		
			resetContestants();
			
			for(int i=0;i<contestants.size();i++){
				
				contestants[i].calcDistance(iterations_count);
			}
			
			sort(contestants.begin(), contestants.end(), [](Contestant c1, Contestant c2) {return c1.getDistance() > c2.getDistance();});
			
			return getContestantStanding();
		}
		
		string getContestantStanding(){
		
			ostringstream out;
			
			for(int i=0;i<contestants.size();i++){
			
				out << contestants[i].getName() << ": ";
				out <<contestants[i].getDistance() << '(';
				out << contestants[i].getSpeed() << ")\n";
			}
			
			string data = out.str();
			
			return data;
		}
};

int main() {

	vector<Contestant> contestants;
	Contestant goshko("goshko", 6);
	Contestant vesko("vesko", 15);
	Contestant bobi("bopkata", 2);
	Contestant sashko("sashko", 1);
	
	contestants.push_back(goshko);
	contestants.push_back(vesko);
	contestants.push_back(bobi);
	
	Race race1(contestants);
	
	race1.addContestant(sashko);
	//ace1.simulateRace(10);
	
	string data = race1.simulateRace(10);
	cout << data << endl;
	
	istringstream in(data);
	double speed_of_vesko;
	string name_of_vesko;
	in >> name_of_vesko;
	//in.ignore(7);
	in >> speed_of_vesko;
	cout << speed_of_vesko << endl;
	cout << name_of_vesko << '!' << endl;
	
	
	
	return 1;
}












