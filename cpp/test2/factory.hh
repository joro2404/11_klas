#ifndef FACTORY_HH
#define FACTORY_HH
#include <string>
#include <vector>
#include "process.hh"
#include "exception.hh"


class Factory{

    public:
        std::string name;
        std::vector <Process> processes; //processes = steps, malumni naimenovaniq sorrka mn oburkvashto....

        Factory(std::string name, std::vector <Process> processes);
        void add_process(std::vector <Material> materials, std::string description, float time, float quality);
        float get_total_time();
        std::vector <Material> get_all_materials();
        float get_total_quality();
        std::string get_report();

};

#endif