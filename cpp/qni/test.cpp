using namespace std;
#include<stdio.h>
#include<string>
#include<list>

class Flight {
    public:
        string id;
        string date;
        string hour;
        bool isCanceled;
    bool equals(Flight flight) {
        if(flight.id == this->id 
        && flight.date == this->date
        && flight.hour == this->hour) { 
            return true;
        }
        return false;
    }
};

class FlightSchedule {
    list<Flight> flights;

    public:
        FlightSchedule() { }

        FlightSchedule(list<Flight> flights) {
            this->flights = flights;
        }

        list<Flight> GetFlights() {
            return flights;
        }

        void addFlight(Flight new_flight) {
            
            list<Flight>::iterator it;
            for(it = flights.begin(); it != flights.end(); it++){
                if((*it).equals(new_flight)) {
                    throw "This flight already exists.";
                }
            }
            flights.push_back(new_flight);
        }

        void setCancelled(Flight toCancel) {
            list<Flight>::iterator it;
            bool exists = false;
            for(it = flights.begin(); it != flights.end(); it++){
                if(toCancel.equals(*it)){
                    exists = true;
                }
            } 
            if(!exists) {
                throw "Flights does not exist.";
            }
            toCancel.isCanceled = true;
        }

        list<Flight> findForDate(string date) {
            list<Flight>::iterator it;
            list<Flight> flightsOnDate;
            for(it = flights.begin(); it != flights.end(); it++){
                if((*it).date == date){
                    flightsOnDate.push_back(*it);
                }
            }
        }

        string toString() {
            string ss;
            list<Flight>::iterator it;
            list<Flight> flightsOnDate;
            for(it = flights.begin(); it != flights.end(); it++){
                //ss+= (*it);
            }
        }

};

int main(int argc, char *argv[]) {

    return 0;
}