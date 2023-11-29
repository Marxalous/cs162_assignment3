#include "shop.h"
#include <iostream>

using namespace std;

/*********************************************************************
** Function: Shop::Shop()
** Description: Default constructor for Shop class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Creates a Shop object with default values
*********************************************************************/
Shop::Shop() {
	this->phone = "";
	this->address = "";
	this->revenue = 0;
	this->order_arr = nullptr;
	this->num_orders = 0;
}

/*********************************************************************
** Function: Shop::Shop(string phone, string address, float revenue, int num_orders)
** Description: Non-default constructor for Shop class
** Parameters: phone - shop phone number, address - shop address,
**             revenue - shop revenue, num_orders - number of orders
** Pre-Conditions: None
** Post-Conditions: Creates a Shop object with specified values
*********************************************************************/
Shop::Shop(string phone, string address, float revenue, int num_orders) {
	this->phone = phone;
	this->address = address;
	this->revenue = revenue;
	this->num_orders = num_orders;
	if (this->num_orders > 0) this->order_arr = new Order[num_orders];
	else this->order_arr = nullptr;
}

/*********************************************************************
** Function: Shop::~Shop()
** Description: Destructor for Shop class
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Deallocates memory for order_arr
*********************************************************************/
Shop::~Shop() {
	if (this->order_arr != NULL) {
		delete [] this->order_arr;
		this->order_arr = NULL;
	}
}

/*********************************************************************
** Function: Shop::Shop(const Shop& s)
** Description: Copy constructor for Shop class
** Parameters: s - Shop object to copy
** Pre-Conditions: Shop object s exists
** Post-Conditions: Creates a copy of Shop object s
*********************************************************************/
Shop::Shop(const Shop& s) {
	this->num_orders = s.num_orders;
	this->order_arr = new Order[num_orders];

	for (int i = 0; i < num_orders; ++i) {
		this->order_arr[i] = s.order_arr[i];
	}
}

/*********************************************************************
** Function: Shop& Shop::operator=(const Shop& s)
** Description: Assignment operator for Shop class
** Parameters: s - Shop object to copy
** Pre-Conditions: Shop object s exists
** Post-Conditions: Assigns the values of Shop object s to the current object
*********************************************************************/
Shop& Shop::operator=(const Shop& s) {
    if (this == &s) return *this;

    if (this->order_arr != NULL) delete [] this->order_arr;

    this->num_orders = s.num_orders;
    this->order_arr = new Order[this->num_orders];
    
    for (int i = 0; i < num_orders; ++i) {
        this->order_arr[i] = s.order_arr[i];
    }

    return *this;
}

/*********************************************************************
** Function: void Shop::set_phone(const string& new_phone)
** Description: Setter function for phone number
** Parameters: new_phone - new phone number
** Pre-Conditions: Shop object exists
** Post-Conditions: Sets the phone number of the shop
*********************************************************************/
void Shop::set_phone(const string& new_phone) {
	this->phone = new_phone;
}

/*********************************************************************
** Function: void Shop::set_address(const string& new_address)
** Description: Setter function for address
** Parameters: new_address - new address
** Pre-Conditions: Shop object exists
** Post-Conditions: Sets the address of the shop
*********************************************************************/
void Shop::set_address(const string& new_address) {
	this->address = new_address;
}

/*********************************************************************
** Function: void Shop::set_revenue(float new_revenue)
** Description: Setter function for revenue
** Parameters: new_revenue - new revenue
** Pre-Conditions: Shop object exists
** Post-Conditions: Sets the revenue of the shop
*********************************************************************/
void Shop::set_revenue(float new_revenue) {
	this->revenue = new_revenue;
}

/*********************************************************************
** Function: void Shop::set_num_orders(int new_num_orders)
** Description: Setter function for number of orders
** Parameters: new_num_orders - new number of orders
** Pre-Conditions: Shop object exists
** Post-Conditions: Sets the number of orders for the shop
*********************************************************************/
void Shop::set_num_orders(int new_num_orders) {
	this->num_orders = new_num_orders;
}

/*********************************************************************
** Function: string Shop::get_phone() const
** Description: Getter function for phone number
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Returns the phone number of the shop
*********************************************************************/
string Shop::get_phone() const {
	return this->phone;
}

/*********************************************************************
** Function: string Shop::get_address() const
** Description: Getter function for address
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Returns the address of the shop
*********************************************************************/
string Shop::get_address() const {
	return this->address;
}

/*********************************************************************
** Function: float Shop::get_revenue() const
** Description: Getter function for revenue
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Returns the revenue of the shop
*********************************************************************/
float Shop::get_revenue() const {
	return this->revenue;
}

/*********************************************************************
** Function: int Shop::get_num_orders() const
** Description: Getter function for number of orders
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Returns the number of orders for the shop
*********************************************************************/
int Shop::get_num_orders() const {
	return this->num_orders;
}

/*********************************************************************
** Function: void Shop::add_revenue_and_orders()
** Description: Initialize revenue and orders in shop_info.txt
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Initializes revenue and orders in shop_info.txt
*********************************************************************/
void Shop::add_revenue_and_orders() {
	// Load shop_info.txt
	ofstream insert_shop_info("shop_info.txt", ios::app);

	// Check if file exists
	if (!insert_shop_info) {
		cerr << "Error loading shop_info.txt" << endl;
		return;
	}

	// Add shop revenue
	insert_shop_info << "\n0.0";

	// Add shop orders
	insert_shop_info << "\n0";
}

/*********************************************************************
** Function: void Shop::make_shop_info()
** Description: Read shop information from shop_info.txt
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Reads shop information from shop_info.txt
*********************************************************************/
void Shop::make_shop_info() {
	// Load shop_info.txt
	ifstream shop_info("shop_info.txt");

	// Check if file exists
	if (!shop_info) {
		cerr << "Error loading shop_info.txt" << endl;
		return;
	}

	string phone, address_1, address_2, address_3;
	float revenue;
	int orders;
	
	// Populate Shop 's' with info from shop_info.txt
	if (shop_info >> phone >> address_1 >> address_2 >> address_3 >> revenue >> orders) {
		// Sets shop phone #
		this->set_phone(phone);
		
		// Sets shop address
		this->set_address(address_1 + " " + address_2 + " " + address_3);
		
		// Sets shop revanue
		this->set_revenue(revenue);
		
		// Sets shop number of orders
		this->set_num_orders(orders);
	}
	else {
		cerr << "Error reading shop_info.txt" << endl;
		return;
	}
}

/*********************************************************************
** Function: void Shop::make_menu_info()
** Description: Read menu information from menu.txt
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Reads menu information from menu.txt
*********************************************************************/
void Shop::make_menu_info() {
	// Load menu.txt
	ifstream menu_info("menu.txt");

	// Check if menu.txt exists
	if (!menu_info) {
		cerr << "Error loading menu.txt" << endl;
		return;
	}

	// Makes an array with the size inputted into menu.txt
	int num_coffee;
	if (menu_info >> num_coffee) {
		// Make temporary array for initialy seeding menu data
		Coffee* temp_arr = new Coffee[num_coffee];

		// For loop for populating each drink's data
		for (int i = 0; i < num_coffee; ++i) {
			string coffee_name;
			float small_cost, medium_cost, large_cost;

			// Make temporary array
			if (menu_info >> coffee_name >> small_cost >> medium_cost >> large_cost) {
				temp_arr[i].set_name(coffee_name);
				temp_arr[i].set_small_cost(small_cost);
				temp_arr[i].set_medium_cost(medium_cost);
				temp_arr[i].set_large_cost(large_cost);
			}
		}

		this->m.set_coffee_arr(temp_arr, num_coffee);

		// Deallocates temp_arr
		if (temp_arr != nullptr) {
			delete [] temp_arr;
			temp_arr = nullptr;
		}
	}
	else {
		cerr << "Error reading menu.txt" << endl;
		return;
	}

	return;
}

/*********************************************************************
** Function: void Shop::make_order_info()
** Description: Read order information from orders.txt
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Reads order information from orders.txt
*********************************************************************/
void Shop::make_order_info() {
	// Write to 0
	ofstream orders_info("orders.txt");
	orders_info << 0;
	orders_info.close();

	// Load orders.txt
	ifstream order_info("orders.txt");

	// Check if orders.txt exists
	if (!order_info) {
		cerr << "Error loading orders.txt" << endl;
		return;
	}

	// Makes an array with the size inputted into menu.txt
	int num_orders;
	if (order_info >> num_orders) {
		// Make temporary array for initialy seeding menu data
		Order* temp_arr = new Order[num_orders];

		// Move over everything from order_arr to the temp_arr
		for (int i = 0; i < num_orders; ++i) {
			temp_arr[i] = order_arr[i];
		}

		this->order_arr = temp_arr;

		// Deallocates temp_arr
		if (temp_arr == nullptr) {
			delete [] temp_arr;
			temp_arr = nullptr;
		}
	}
	else {
		cerr << "Error reading orders.txt" << endl;
		return;
	}

	return;
}

/*********************************************************************
** Function: void Shop::load_data()
** Description: Load data for the shop (shop_info.txt, menu.txt, orders.txt)
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Loads data for the shop
*********************************************************************/
void Shop::load_data() {
	// Set Revenue and Orders to 0 within shop_info.txt
	add_revenue_and_orders();
	
	// Populate shop info
	make_shop_info();

	// Populate menu info
	make_menu_info();

	// Populate order info
	make_order_info();
}

/*********************************************************************
** Function: void Shop::view_shop_detail()
** Description: Display details of the shop and its menu
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Displays details of the shop and its menu
*********************************************************************/
void Shop::view_shop_detail() {
	// Shows the details of the shop
	cout << " _______ __                     _______         ___        \n"
		    "|     __|  |--.-----.-----.    |_     _|.-----.'  _|.-----.\n"
		    "|__     |     |  _  |  _  |     _|   |_ |     |   _||  _  |\n"
		    "|_______|__|__|_____|   __|    |_______||__|__|__|  |_____|\n"
		    "                    |__|                                   \n";

	cout << "\n  Phone:   " << get_phone() << endl
		 <<   "  Address: " << get_address() << endl
		 <<   "  Revenue: $" << get_revenue() << endl
		 <<   "  Orders:  " << get_num_orders() << endl;

	// Prints the menu
	cout << " _______                    \n"
			"|   |   |.-----.-----.--.--.\n"
			"|       ||  -__|     |  |  |\n"
			"|__|_|__||_____|__|__|_____|\n\n";

	this->m.print_menu();

	return;
}

/*********************************************************************
** Function: void Shop::add_to_menu()
** Description: Add a new drink to the menu
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Adds a new drink to the menu
*********************************************************************/
void Shop::add_to_menu() {
	// Add new drink to menu
	Coffee coffee_to_add;
	
	cout << " _______     __     __      __              _______                    \n"
			"|   _   |.--|  |.--|  |    |  |_.-----.    |   |   |.-----.-----.--.--.\n"
			"|       ||  _  ||  _  |    |   _|  _  |    |       ||  -__|     |  |  |\n"
			"|___|___||_____||_____|    |____|_____|    |__|_|__||_____|__|__|_____|\n\n";

	// New drink name
	string new_name;
	cout << "Name of new drink:      ";
	cin >> new_name;
	coffee_to_add.set_name(new_name);

	// New small price
	float new_small;
	cout << "Price of small drink:  $";
	cin >> new_small;
	coffee_to_add.set_small_cost(new_small);

	// New medium price
	float new_medium;
	cout << "Price of medium drink: $";
	cin >> new_medium;
	coffee_to_add.set_medium_cost(new_medium);

	// New large price
	float new_large;
	cout << "Price of large drink:  $";
	cin >> new_large;
	coffee_to_add.set_large_cost(new_large);

	// Add to menu
	this->m.add_to_menu(coffee_to_add);

	return;
}

/*********************************************************************
** Function: void Shop::remove_from_menu()
** Description: Remove a drink from the menu
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Removes a drink from the menu
*********************************************************************/
void Shop::remove_from_menu() {
	// Remove drink from menu
	int num_coffee = this->m.get_num_coffee();

	// Edge case if there are no drinks on the menu
	if (num_coffee == 0) {
		cerr << "This menu is empty, no drinks can be removed";
		return;
	}

	// Display menu for user usability
	cout << " _______                    \n"
			"|   |   |.-----.-----.--.--.\n"
			"|       ||  -__|     |  |  |\n"
			"|__|_|__||_____|__|__|_____|\n\n";

	this->m.print_menu();

	// Drink to remove
	int option;
	cout << " ______                                         ___                           _______                    \n"
			"|   __ \\.-----.--------.-----.--.--.-----.    .'  _|.----.-----.--------.    |   |   |.-----.-----.--.--.\n"
			"|      <|  -__|        |  _  |  |  |  -__|    |   _||   _|  _  |        |    |       ||  -__|     |  |  |\n"
			"|___|__||_____|__|__|__|_____|\\___/|_____|    |__|  |__| |_____|__|__|__|    |__|_|__||_____|__|__|_____|\n\n";

	cout << "Which number drink on the menu would you like to remove? (1-" << num_coffee << ") ";
	cin >> option;

	// Check for valid drink removal
	if (option >= 1 && option <= num_coffee) {
		int index_of_coffee_on_menu = option - 1;

		this->m.remove_from_menu(index_of_coffee_on_menu);
	}
	else {
		cerr << "Invalid option, Please enter a number (1-" << num_coffee << ")" << endl;
		return;
	}

	return;
}

/*********************************************************************
** Function: void Shop::search_by_name()
** Description: Searches for a drink in the menu by name and displays its details.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Displays details of the found drink or an error message.
*********************************************************************/
void Shop::search_by_name(){
	// Search by drink name
	string name;
	Coffee name_of;

	cout << " _______                         __         __               _______                       \n"
			"|     __|.-----.---.-.----.----.|  |--.    |  |--.--.--.    |    |  |.---.-.--------.-----.\n"
			"|__     ||  -__|  _  |   _|  __||     |    |  _  |  |  |    |       ||  _  |        |  -__|\n"
			"|_______||_____|___._|__| |____||__|__|    |_____|___  |    |__|____||___._|__|__|__|_____|\n"
			"                                                 |_____|                                   \n\n";

	// User input
	cout << "Please enter coffee name: ";
	cin >> name;

	// Runs search_coffee_by_name() with the user input
	name_of = this->m.search_coffee_by_name(name);

	// Checks if the user input is valid
	if (name_of.get_name() == "") {
		cerr << "No drinks with this name found on the menu. Please try again..." << endl;
		return;
	}
	else {
		cout << endl << name_of.get_name() << endl <<
			 "  s: " << name_of.get_small_cost() << endl <<
			 "  m: " << name_of.get_medium_cost() << endl <<
			 "  l: " << name_of.get_large_cost() << endl;
	}

	return;
}

/*********************************************************************
** Function: void Shop::search_by_price()
** Description: Searches for drinks within a budget and displays their names and prices.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Displays names and prices of drinks within the provided budget or an error message.
*********************************************************************/
void Shop::search_by_price(){
	// Search drinks by max price
	float budget;
	Menu in_budget;
	
	cout << " _______                         __         __               ______        __             \n"
			"|     __|.-----.---.-.----.----.|  |--.    |  |--.--.--.    |   __ \\.----.|__|.----.-----.\n"
			"|__     ||  -__|  _  |   _|  __||     |    |  _  |  |  |    |    __/|   _||  ||  __|  -__|\n"
			"|_______||_____|___._|__| |____||__|__|    |_____|___  |    |___|   |__|  |__||____|_____|\n"
			"                                                 |_____|                                  \n\n";

	// User input
	cout << "What is your budget? $";
	cin >> budget;
	cout << endl;

	// Run search_coffee_by_price() with the user input
	in_budget = this->m.search_coffee_by_price(budget);

	// Checks if the user input is valid
	if (in_budget.get_num_coffee() == 0) {
		cerr << "No drinks within your provided budget. Please try again..." << endl;
		return;
	}
	else {
		for (int i = 0; i < in_budget.get_num_coffee(); ++i) {
			cout << in_budget.get_coffee_arr()[i].get_name() << endl;
			if (in_budget.get_coffee_arr()[i].get_small_cost() <= budget) {
				cout << "   s: " << in_budget.get_coffee_arr()[i].get_small_cost() << endl;
			}
			if (in_budget.get_coffee_arr()[i].get_medium_cost() <= budget) {
				cout << "   m: " << in_budget.get_coffee_arr()[i].get_medium_cost() << endl;
			}
			if (in_budget.get_coffee_arr()[i].get_large_cost() <= budget) {
				cout << "   l: " << in_budget.get_coffee_arr()[i].get_large_cost() << endl;
			}
		}
	}

	return;
}

/*********************************************************************
** Function: void Shop::place_order()
** Description: Places an order by taking user input for drink, size, and quantity.
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Updates order details and displays a confirmation message.
*********************************************************************/
void Shop::place_order() {
	Order order_to_add;

	// Display menu
    cout << " _______                    \n"
			"|   |   |.-----.-----.--.--.\n"
			"|       ||  -__|     |  |  |\n"
			"|__|_|__||_____|__|__|_____|\n\n";

    this->m.print_menu();

    // Prompt for order details
    string drink_size;
    float drink_cost = 0;

    string drink;
    char size;
    int quantity = 0;

	cout << " ______ __                                         _______          __             \n"
			"|   __ \\  |.---.-.----.-----.    .---.-.-----.    |       |.----.--|  |.-----.----.\n"
			"|    __/  ||  _  |  __|  -__|    |  _  |     |    |   -   ||   _|  _  ||  -__|   _|\n"
			"|___|  |__||___._|____|_____|    |___._|__|__|    |_______||__| |_____||_____|__|  \n\n";

    cout << "What kind of drink would you like to order from the menu? ";
    cin >> drink;

	// Search for the selected drink in the menu
    for (int i = 0; i < this->m.get_num_coffee(); ++i) {
        if (drink == this->m.get_coffee_arr()[i].get_name()) {
            order_to_add.set_coffee_name(drink);
			// Prompt for drink size
            do {
                cout << "\nWhat size would you like?\n  s = small\n  m = medium\n  l = large\nSize: ";
                cin >> size;
				order_to_add.set_coffee_size(size);

                if (size == 's') {
                    drink_size = "small";
                    drink_cost = this->m.get_coffee_arr()[i].get_small_cost();
                }
                else if (size == 'm') {
                    drink_size = "medium";
                    drink_cost = this->m.get_coffee_arr()[i].get_medium_cost();
                }
                else if (size == 'l') {
                    drink_size = "large";
                    drink_cost = this->m.get_coffee_arr()[i].get_large_cost();
                }
            } while (size != 's' && size != 'm' && size != 'l');

            // Display order details
            cout << "\nA " << drink_size << " " << this->m.get_coffee_arr()[i].get_name() << " will cost $" << drink_cost << endl;

            // Prompt for order quantity
            do {
                cout << "\nHow many would you like to order? ";
                cin >> quantity;
				order_to_add.set_quantity(quantity);

                if (quantity <= 0) cout << "\nPlease enter in a quantity that is more than or equal to 1" << endl;

            } while (quantity <= 0);
		}
	} 

	order_to_add.set_id(num_orders + 1);

	// Increase revenue
	revenue += order_to_add.get_quantity() * drink_cost;

	order_place(order_to_add);	
}

/*********************************************************************
** Function: void Shop::order_place(Order& order_to_add)
** Description: Places an order by adding it to the order list and updating the order file.
** Parameters: order_to_add - Order object representing the new order
** Pre-Conditions: Shop object exists
** Post-Conditions: Adds the new order to the order list and updates the order file.
*********************************************************************/
void Shop::order_place(Order& order_to_add) {
	// Create temp_arr
	Order* temp_arr = new Order[(num_orders + 1)];

	// Move over everything from num_orders to the temp_arr
	for (int i = 0; i < num_orders; ++i) {
		temp_arr[i] = order_arr[i];
	}

	// Add new drink to the end of the array
	temp_arr[num_orders] = order_to_add;

	// Add new drink on the menu
	++num_orders;

	// Deallocate coffee_arr
	if (this->order_arr != nullptr) {
		delete [] order_arr;
		this->order_arr = temp_arr;
	}

	// Update menu.txt
	update_order_file();

	return;
}

/*********************************************************************
** Function: void Shop::update_order_file() const
** Description: Updates the "orders.txt" file with the current order details.
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: The "orders.txt" file is updated with the current order information.
*********************************************************************/
void Shop::update_order_file() const {
	// Open orders.txt
	ofstream orders_info("orders.txt");

	// Check if it opens properly
	if (!orders_info.is_open()) {
		cerr << "Error updating orders.txt" << endl;
		return;
	}

	// Set the number of drinks as the first line within the file
	orders_info << num_orders;

	// Sets the rest of the drinks
	for (int i = 0; i < num_orders; ++i) {
		orders_info << endl << this->order_arr[i].get_id() << " "
							<< this->order_arr[i].get_coffee_name() << " "
							<< this->order_arr[i].get_coffee_size() << " "
							<< this->order_arr[i].get_quantity();
	}

	// Closes the file
	orders_info.close();
}

/*********************************************************************
** Function: Shop Shop::clone_shop()
** Description: Creates and returns a clone of the current Shop object.
**              Used for testing the copy constructor and assignment operator.
** Parameters: None
** Pre-Conditions: Shop object exists
** Post-Conditions: Creates a clone of the current Shop object and prints a success message.
*********************************************************************/
Shop Shop::clone_shop() {
	//handle "Clone a shop" option
	//note: the purpose of this option is to test
	//your big three implementation
	Shop cloned_shop;

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}