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
vector<Warehouse> warehouses;

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
	
	scanf("%d", &total_warehouses);
	for (int it = 0; it < total_warehouses; it++)
	{
		int war_x, war_y;
		scanf("%d %d", war_x, war_y);
		Warehouse* warehouse = new Warehouse(war_x, war_y);
		string warhouse_prod;
		getline(cin, warhouse_prod);
		string war_buffer;
		stringstream warss(warhouse_prod);

		int prod_id = 0;
		while (warss >> war_buffer)
		{
			int count = std::stoi(war_buffer);
			if (count <= 0)
			{
				continue;
			}
			else
			{
				warehouse->add_product(products.at(sizeof(Product)*prod_id).weight, count);
			}
			prod_id++;
		}
	}


	return 0;
}

