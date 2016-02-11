#include "Main.h"
#include <vector>

using namespace std;

int rows;
int cols;
int number_of_drones;
int turns;
int max_payload;

struct Product
{
    int weight;
    int count;
    Product(int weight_, int count_) : weight(weight_), count(count_) { }
};

class Warehouse
{
public:
    int x;
    int y;
    vector<Product> products;

    Warehouse(int x_, int y_) : x(x_), y(y_) { }
    void add_product(int weight, int count) {
        products.push_back(Product(weight, count));
    }
};

int main(int argc, const char* argv[])
{
	return 0;
}

