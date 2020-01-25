#include "process.hh"

Process::Process(int id, std::string description, std::vector <Material> materials, float quality, float time_needed){
    this->id = id;
    this->description = description;
    this->materials = materials;
    this->quality = quality;
    this->time_needed = time_needed;
}