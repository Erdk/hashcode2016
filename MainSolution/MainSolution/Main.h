#ifndef _MAIN_H_
#define _MAIN_H_

#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

struct Product
{
	int prod_id;
	int weight;
	int count;
	Product(int weight_) : weight(weight_) { }
	Product(int weight_, int count_) : weight(weight_), count(count_) { }
};

struct Point
{
    int x, y;
    Point() : x(0), y(0) { }
    Point(int x_, int y_) : x(x_), y(y_) { }
};

struct Drone : public Point
{
    int cur_load;
    bool free;

    Drone(): cur_load(0), free(true), Point() { }

    // sets destination for drone
    int deliver(int dest_x, int dest_y) {
        int turns = ceil(sqrt(pow(dest_x - x, 2) + pow(dest_y - y, 2)));
        x = dest_x;
        y = dest_y;
        return turns;
    }
};

struct Warehouse : public Point
{
	map<int, Product> products;
	//vector<Product> products;

	Warehouse(int x_, int y_) : Point(x_, y_) { }
	void add_product(int prod_id, int weight, int count) {
		//products.push_back(Product(weight, count));
		products.emplace(prod_id, Product(weight, count));
	}
};

struct Customer : public Point
{
	map<int,int> orders;
	Customer(int x_, int y_) : Point(x_, y_) { }
};

#endif
