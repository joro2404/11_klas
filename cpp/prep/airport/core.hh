#ifndef CORE_HH
#define CORE_HH

class core {
    public:
        int size;
        int number_of_flight;
        char model[256];
        double speed;
        double fuel;
        double fuel_per_km;
        int X; //???
        core operator<<(core plane_1);
};

#endif