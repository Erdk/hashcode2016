#include "Main.h"

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
vector<Drone> drones;

int distance(Point a, Point b)
{
    return (int) ceil(sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0)));
}

int customer_weight(Customer c)
{
	int weight = 0;
	for (auto it = c.orders.cbegin(); it != c.orders.cend(); ++it)
	{
		weight += (products[it->first].weight * it->second);
	}
	return weight;
}

Drone find_drone(Customer c)
{
    int dst = INT_MAX;
    int drone;
    for (int i = 0; i < total_drones; i++) {
        if (!drones[i].free)
            continue;
        int c_d_dst = distance(c, drones[i]);
        if (c_d_dst < dst) {
            dst = c_d_dst;
            drone = i;
        }
    }

    return Drone();
}

void process_customer(Customer c, Drone d)
{
}

int main(int argc, const char* argv[])
{
	scanf("%d %d %d %d %d\n", &rows, &cols, &total_drones, &turns, &max_payload);
	scanf("%d\n", &total_products);
	string product_line;
	string buffer;
	getline(cin, product_line);
	
	stringstream ss(product_line);

	while (ss >> buffer)
	{
		total_products++;
		products.push_back(Product(std::stoi(buffer)));
	}
	
	scanf("%d\n", &total_warehouses);
	for (int it = 0; it < total_warehouses; it++)
	{
		int war_x, war_y;
		scanf("%d %d\n", &war_x, &war_y);
		Warehouse warehouse = Warehouse(war_x, war_y);
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
				warehouse.add_product(prod_id, products.at(prod_id).weight, count);
			}
			prod_id++;
		}

        warehouses.push_back(warehouse);
	}

	scanf("%d\n", &total_orders);

	for (int it = 0; it < total_orders; it++)
	{
		int loc_x, loc_y;
		scanf("%d %d\n", &loc_x, &loc_y);
		Customer customer = Customer(loc_x, loc_y);
		int number_of_prod_orders;
		scanf("%d\n", &number_of_prod_orders);
        string orders;
        string order_buffer;
        getline(cin, orders);
        stringstream orders_ss(orders);
        while (orders_ss >> order_buffer)
        {
            int prod_id = std::stoi(order_buffer);
            if (customer.orders.find(prod_id) == customer.orders.end())
            {
                customer.orders.emplace(prod_id, 1);
            }
            else
            {
                customer.orders.at(prod_id)++;
            }
        }
		customers.push_back(customer);
	}


	return 0;
}

	