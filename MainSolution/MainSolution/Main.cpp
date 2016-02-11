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
int total_orders = 0;
vector<Product> products;
vector<Warehouse> warehouses;
vector<Customer> customers;

int distance_c_w(Customer c, Warehouse w) {
	return (int) ceil(sqrt(pow(c.x - w.x, 2.0) + pow(c.y - w.y, 2.0)));
}

int main(int argc, const char* argv[])
{
	scanf_s("%d %d %d %d %d", &rows, &cols, &total_drones, &turns, &max_payload);
	string product_line;
	string buffer;
	getline(cin, product_line);
	
	stringstream ss(product_line);

	while (ss >> buffer)
	{
		total_products++;
		products.push_back(Product(std::stoi(buffer)));
	}
	
	scanf_s("%d", &total_warehouses);
	for (int it = 0; it < total_warehouses; it++)
	{
		int war_x, war_y;
		scanf_s("%d %d", war_x, war_y);
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
				warehouse->add_product(prod_id, products.at(prod_id).weight, count);
			}
			prod_id++;
		}
	}

	scanf_s("%d", &total_orders);

	for (int it = 0; it < total_orders; it++)
	{
		int loc_x, loc_y;
		scanf_s("%d %d", loc_x, loc_y);
		Customer* customer = new Customer(loc_x, loc_y);
		int number_of_prod_orders;
		scanf_s("%d", &number_of_prod_orders);
		for (int prod_order_it = 0; prod_order_it < number_of_prod_orders; prod_order_it++)
		{
			string orders;
			string order_buffer;
			getline(cin, orders);
			stringstream orders_ss(orders);
			while (orders_ss >> order_buffer)
			{
				int prod_id = std::stoi(order_buffer);
				if (customer->orders.find(prod_id) == customer->orders.end())
				{
					customer->orders.insert(prod_id, 1);
				}
				else
				{
					customer->orders.at(prod_id)++;
				}
			}
		}
		customers.push_back(*customer);
	}

	return 0;
}

