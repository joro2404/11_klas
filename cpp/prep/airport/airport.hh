#ifndef AIRPORT_HH
#define AIRPORT_HH
#include <vector>
#include "core.hh"
using namespace std;

class aiport{
    public:
        int max_planes;
        int max_size_of_planes;
        bool military;
        bool civil;
        vector<core> planes;
        int X;

        int can_fit_plane(const core& plane);
        void land_plane(const core& plane);
};

#endif