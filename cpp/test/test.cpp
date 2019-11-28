#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Oneexception{

    string message;

    public:

        Oneexception(string message){
            this->message = message;
        }

        string what(){
            return message;
        }
};

class Flight{

    public:

        string number_of_flight;
        string date;
        string hour;
        int cancel;

};

class FlightSchedule{

    vector<Flight> flights;

    public:

        FlightSchedule(){}

        FlightSchedule(vector<Flight> flights){
            this->flights = flights;
        }

        vector<Flight> getFlights(){
            return flights;
        }

        void addFlight(Flight newFlight){

            for(int i=0;i<flights.size();i++){

                if(flights[i].date == newFlight.date && flights[i].number_of_flight == newFlight.number_of_flight && flights[i].hour == newFlight.hour)throw Oneexception("You have same flight here! \n");
            }

            flights.push_back(newFlight);
        }

        void setCancelled(Flight toCancel){
            
            int checker = 0;

            for(int i=0;i<flights.size();i++){

                if(flights[i].date == toCancel.date && flights[i].number_of_flight == toCancel.number_of_flight && flights[i].hour == toCancel.hour)throw Oneexception("You must have flight to cancel it! \n");
            }
            toCancel.cancel = 1;
        }

        vector<Flight> findForDate(string date){

            vector<Flight> ondate;

            for(int i=0;i<flights.size();i++){

                if(flights[i].date == date){
                    ondate.push_back(flights[i]);
                }
            }

            return ondate;
        }


        string toString(){

            ostringstream out;

            for(int i=0;i<flights.size();i++){

                out << flights[i].number_of_flight << ' ';
                out << flights[i].date << ' ';
                out << flights[i].hour << ' ';
                out << flights[i].cancel << "\n";
            }

            return out.str();
        }
};

int main() {

    vector<Flight> flights;

    Flight flight1;
    flight1.number_of_flight = "BB123";
    flight1.hour = "3:00";
    flight1.date = "24.04";
    flight1.cancel = 0;
    flights.push_back(flight1);

    Flight flight2;
    flight2.number_of_flight = "AB135";
    flight2.hour = "5:00";
    flight2.date = "13.02";
    flight2.cancel = 1;
    flights.push_back(flight2);

    Flight flight3;
    flight3.number_of_flight = "AB135";
    flight3.hour = "5:00";
    flight3.date = "13.02";
    flight3.cancel = 1;
    //flights.push_back(flight2);

    FlightSchedule schedule(flights);

    try{

        schedule.addFlight(flight3);
    }catch(Oneexception ex){
        cout << ex.what() << endl;
    }

    cout << schedule.toString() << endl;
    
    return 0;
}   