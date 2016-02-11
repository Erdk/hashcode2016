#ifndef _MAIN_H_
#define _MAIN_H_

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

struct Product
{
	int weight;
	int count;
	Product(int weight_) : weight(weight_) { }
	Product(int weight_, int count_) : weight(weight_), count(count_) { }
};

struct Warehouse
{
	int x, y;
	vector<Product> products;

	Warehouse(int x_, int y_) : x(x_), y(y_) { }
	void add_product(int weight, int count) {
		products.push_back(Product(weight, count));
	}
};

struct Customer
{
	int x, y;
	map<int,int> orders;
	Customer(int location_x_, int location_y_) : x(location_x_), y(location_y_) { }
};

#endif
