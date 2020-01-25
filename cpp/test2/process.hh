#ifndef PROCESS_HH
#define PROCESS_HH
#include <string>
#include <vector>
#include "material.hh"

class Process { //step

    public:

        int id;
        std::string description;
        std::vector <Material> materials;
        float quality;
        float time_needed;

        Process(int id, std::string description, std::vector <Material> materials, float quality, float time_needed);
};

#endif