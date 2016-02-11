#ifndef _DRONE_H_
#define _DRONE_H

#include <cmath>
#include "Main.h"

struct Drone
{
    int x, y;
    int max_load;
    int cur_load;

    Drone(int max_load_): max_load(max_load) { }

    // sets destination for drone
    int deliver(int dest_x, int dest_y) {
        int turns = ceil(sqrt(pow(dest_x - x, 2) + pow(dest_y - y, 2)));
        x = dest_x;
        y = dest_y;
        return turns;
    }
};

#endif //_DRONE_H_
