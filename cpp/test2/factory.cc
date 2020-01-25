#include "factory.hh"

Factory::Factory(std::string name, std::vector <Process> processes){

    this->name = name;
    this->processes = processes;
}

void Factory::add_process(std::vector <Material> materials, std::string description, float time, float quality){

    if(materials.size() <= 0)throw Exception("the materials vector is empty!");
    if(time <= 0)throw Exception("No time included!");
    int id = this->processes.size();
    Process process(id, description, materials, quality, time);
    this->processes.push_back(process);
}

float Factory::get_total_time(){

    float total_time = 0;
    if(this->processes.size() <= 0)throw Exception("No declared steps!");

    for (int i = 0; i < this->processes.size(); i++){
        if(processes[i].time_needed <= 0)throw Exception("No time declared for this process");
        total_time += processes[i].time_needed;
    }

    return total_time;
}

std::vector <Material> Factory::get_all_materials(){

    std::vector <Material> all_materials;
    if(this->processes.size() <= 0)throw Exception("No declared steps!");

    for (int i = 0; i < this->processes.size(); i++){
        if(processes[i].materials.size() <= 0)throw Exception("No materials in the step!");
        for (int j = 0; j < processes[i].materials.size(); j++){
            all_materials.push_back(this->processes[i].materials[j]);
        }
    }

    return all_materials;    
}

float Factory::get_total_quality(){

    float total_quality = 1;
    if(this->processes.size() <= 0)throw Exception("No declared steps!");

    for (int i = 0; i < this->processes.size(); i++){
        if(this->processes[i].quality <= 5)throw Exception("quality under 5%!");
        total_quality *= this->processes[i].quality;
    }

    return total_quality;
}

std::string Factory::get_report(){

    std::string report= "";
    std::vector <Material> all_materials = get_all_materials();
    float total_time = get_total_time();
    float total_quality = get_total_quality();
    int total_steps = this->processes.size();
    report += " REPORT ";

    for (int i = 0; i < all_materials.size(); i++){
        if(i != 0)report += "\n";
        report += all_materials[i].name;
    }
    report += "\ntotal time: ";
    report += total_time;
    report += "\ntotal quality: ";
    report += total_quality;
    report += "\ntotal steps: ";
    report += total_steps;

    return report;
}