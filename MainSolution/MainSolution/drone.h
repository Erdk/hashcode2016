#ifndef _DRONE_H_
#define _DRONE_H

#include <cmath>

class Drone
{
    int x, y;
    int dest_x, dest_y;
    int max_load;
    int cur_load;

public:
    Drone(int max_load_): max_load(max_load) { }
    void load();
    void deliver();
    void unload();
    void wait();
    // sets destination for drone
    void move(int dest_x_, int dest_y_) { dest_x = dest_x_; dest_y = dest_y_; }
    int availability() const { return (int) floor(sqrt(pow(dest_x - x, 2) + pow(dest_y - y, 2))); }
};

#endif //_DRONE_H_
