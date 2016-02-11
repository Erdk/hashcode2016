#include "Main.h"
#include "drone.h"

using namespace std;

int rows;
int cols;
int total_drones;
int turns;
int max_payload;
int total_products = 0;
int total_warehouses = 0;
vector<Product> products;

int main(int argc, const char* argv[])
{
	scanf("%d %d %d %d %d", &rows, &cols, &total_drones, &turns, &max_payload);
	string product_line;
	string buffer;
	getline(cin, product_line);
	
	stringstream ss(product_line);

	while (ss >> buffer)
	{
		total_products++;
		products.push_back(Product(std::stoi(buffer)));
	}
	


	return 0;
}

