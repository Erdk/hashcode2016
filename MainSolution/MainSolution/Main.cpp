#include "Main.h"
#include "drone.h"

using namespace std;

int rows;
int cols;
int number_of_drones;
int turns;
int max_payload;
vector<Product> products;

int main(int argc, const char* argv[])
{
	scanf("%d %d %d %d %d", &rows, &cols, &number_of_drones, &turns, &max_payload);
	string product_line;
	string buffer;
	getline(cin, product_line);
	
	stringstream ss(product_line);

	while (ss >> buffer)
	{
		products.push_back(Product(std::stoi(buffer)));
	}
	
	return 0;
}

