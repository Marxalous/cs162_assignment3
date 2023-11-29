/*********************************************************************
** Program Filename: menu.cpp
** Author: Matthew McMahon
** Date: 11/12/2023
** Description: cpp file that contains the functions for the Menu class
** Input: menu.h
** Output: functions for the class Menu
*********************************************************************/

#include "menu.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*********************************************************************
** Function: Menu::Menu()
** Description: Default constructor for the Menu class. Initializes the number of coffee items and the coffee array to default values.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A Menu object is created with default values.
*********************************************************************/
Menu::Menu() {
	this->num_coffee = 0;
	this->coffee_arr = NULL;
}

/*********************************************************************
** Function: Menu::Menu(int c)
** Description: Non-default constructor for the Menu class. Initializes the number of coffee items and allocates memory for the coffee array based on the given size.
** Parameters: c - an integer representing the number of coffee items
** Pre-Conditions: None
** Post-Conditions: A Menu object is created with the specified number of coffee items.
*********************************************************************/
Menu::Menu(int c) {
	this->num_coffee = c;
	this->coffee_arr = new Coffee[c];
}

/*********************************************************************
** Function: Menu::~Menu()
** Description: Destructor for the Menu class. Deallocates memory used for the coffee array.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Memory used for the coffee array is freed.
*********************************************************************/
Menu::~Menu() {
	if (this->coffee_arr != NULL) {
		delete [] this->coffee_arr;
		this->coffee_arr = NULL;
	}
}

/*********************************************************************
** Function: Menu::Menu(const Menu& m)
** Description: Copy constructor for the Menu class. Creates a new Menu object by copying the content of an existing Menu object.
** Parameters: m - a constant reference to a Menu object
** Pre-Conditions: None
** Post-Conditions: A new Menu object is created as a copy of the provided Menu object.
*********************************************************************/
Menu::Menu(const Menu& m) {
	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee[num_coffee];

	for (int i = 0; i < num_coffee; ++i) {
		this->coffee_arr[i] = m.coffee_arr[i];
	}
}

/*********************************************************************
** Function: Menu& Menu::operator=(const Menu& m)
** Description: Assignment operator for the Menu class. Assigns the content of one Menu object to another.
** Parameters: m - a constant reference to a Menu object
** Pre-Conditions: None
** Post-Conditions: The content of the Menu object is replaced with the content of the provided Menu object.
*********************************************************************/
Menu& Menu::operator=(const Menu& m) {
	if (this == &m) return *this;

	if (this->coffee_arr != NULL) delete [] this->coffee_arr;

	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee[this->num_coffee];

	for (int i = 0; i < num_coffee; ++i) {
		this->coffee_arr[i] = m.coffee_arr[i];
	}

	return *this;
}

/*********************************************************************
** Function: Coffee Menu::search_coffee_by_name(string name)
** Description: Searches for a coffee item in the menu by its name and returns the corresponding Coffee object.
** Parameters: name - a string representing the name of the coffee
** Pre-Conditions: None
** Post-Conditions: If a matching coffee is found, the corresponding Coffee object is returned; otherwise, an empty Coffee object is returned.
*********************************************************************/
Coffee Menu::search_coffee_by_name(string name) {
	Coffee found;

	// Looks for and checks if there is a matching name
	for (int i = 0; i < num_coffee; ++i) {
		if (this->coffee_arr[i].get_name() == name) {
			found = this->coffee_arr[i];
		}
	}

	return found;
}

/*********************************************************************
** Function: Menu Menu::search_coffee_by_price(float budget)
** Description: Searches for coffee items in the menu with a cost equal to or lower than the specified budget and returns a new Menu object containing the matching coffee items.
** Parameters: budget - a float representing the budget for the coffee
** Pre-Conditions: None
** Post-Conditions: A new Menu object is returned containing coffee items with costs equal to or lower than the specified budget.
*********************************************************************/
Menu Menu::search_coffee_by_price(float budget){
	Menu temp;

	// Looks for and checks if there are any drinks under user inputted price
	for (int i = 0; i < this->num_coffee; ++i) {

		// For large
		if (this->coffee_arr[i].get_large_cost() <= budget) {
			temp.add_to_pseudo_menu(this->coffee_arr[i]);
		}
		// For medium
		else if (this->coffee_arr[i].get_medium_cost() <= budget) {
			temp.add_to_pseudo_menu(this->coffee_arr[i]);
		}
		// For small
		else if (this->coffee_arr[i].get_small_cost() <= budget) {
			temp.add_to_pseudo_menu(this->coffee_arr[i]);
		}
	}

	return temp;
}

/*********************************************************************
** Function: void Menu::add_to_menu(Coffee& coffee_to_add)
** Description: Adds a new coffee item to the menu.
** Parameters: coffee_to_add - a reference to the Coffee object to be added to the menu
** Pre-Conditions: None
** Post-Conditions: The specified Coffee object is added to the menu, and the menu is updated.
*********************************************************************/
void Menu::add_to_menu(const Coffee& coffee_to_add){
	// Create temp_arr
	Coffee* temp_arr = new Coffee[num_coffee + 1];

	// Move over everything from num_coffee to the temp_arr
	for (int i = 0; i < this->num_coffee; ++i) {
		temp_arr[i] = Coffee(this->coffee_arr[i]);
	}

	// Add new drink to the end of the array
	temp_arr[num_coffee] = coffee_to_add;

	// Add new drink on the menu
	++num_coffee;

	// Deallocate coffee_arr
	delete [] coffee_arr;
	this->coffee_arr = NULL;

	// Reallocate it and set it to = temp_arr
	this->coffee_arr = temp_arr;

	// Update menu.txt
	update_menu_file();

	return;
}

/*********************************************************************
** Function: void Menu::remove_from_menu(int index_of_coffee_on_menu)
** Description: Removes a coffee item from the menu at the specified index.
** Parameters: index_of_coffee_on_menu - an integer representing the index of the coffee item to be removed
** Pre-Conditions: None
** Post-Conditions: The specified Coffee object is removed from the menu, and the menu is updated.
*********************************************************************/
void Menu::remove_from_menu(int index_of_coffee_on_menu) {
	// Checks for incorrect input
	if (index_of_coffee_on_menu < 0 || index_of_coffee_on_menu >= num_coffee) {
		cerr << "Invalid option, Please enter a number (1-" << num_coffee << ")" << endl;
		return;
	}

	// Create temp_arr
	Coffee* temp_arr = new Coffee[this->num_coffee - 1];

	// Move over everything from num_coffee to the temp_arr
	for (int i = 0; i < index_of_coffee_on_menu; ++i) {
		temp_arr[i] = this->coffee_arr[i];
	}

	for (int i = index_of_coffee_on_menu + 1; i < num_coffee; ++i) {
		temp_arr[i - 1] = this->coffee_arr[i];
	} 

	// Removes removed drink from the number of drinks
	--num_coffee;

	// Deallocate coffee_arr
	delete [] coffee_arr;
	this->coffee_arr = NULL;

	// Reallocate it and set it to = temp_arr
	this->coffee_arr = temp_arr;

	// Update menu.txt
	update_menu_file();

	return;
}

/*********************************************************************
** Function: void Menu::set_coffee_arr(const Coffee* temp_arr, int num_coffee)
** Description: Sets the coffee array of the menu to the specified array and size.
** Parameters: temp_arr - a constant pointer to a Coffee array, num_coffee - an integer representing the size of the array
** Pre-Conditions: None
** Post-Conditions: The coffee array of the menu is set to the specified array and size.
*********************************************************************/
void Menu::set_coffee_arr(const Coffee* temp_arr, int num_coffee) {
	// Gets this object's num_coffee and sets it to the number of coffee
	this->num_coffee = num_coffee;

	// Creates array with size num_coffee
	this->coffee_arr = new Coffee[num_coffee];

	// Copies data from the temp array
	for (int i = 0; i < num_coffee; ++i) {
		this->coffee_arr[i] = temp_arr[i];
	}
}

/*********************************************************************
** Function: Coffee* Menu::get_coffee_arr() const
** Description: Getter function to retrieve the coffee array of the menu.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The coffee array of the menu is returned.
*********************************************************************/
Coffee* Menu::get_coffee_arr() const {
	return this->coffee_arr;
}

/*********************************************************************
** Function: int Menu::get_num_coffee() const
** Description: Getter function to retrieve the number of coffee items in the menu.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The number of coffee items in the menu is returned.
*********************************************************************/
int Menu::get_num_coffee() const {
	return this->num_coffee;
}

/*********************************************************************
** Function: void Menu::print_menu() const
** Description: Prints the details of each coffee item in the menu.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The details of each coffee item in the menu are printed to the console.
*********************************************************************/
void Menu::print_menu() const {
	// Prints a menu for each of the drinks
	for (int i = 0; i < this->num_coffee; ++i) {
		cout << "  " << this->coffee_arr[i].get_name() << endl;
		cout << "   s: " << this->coffee_arr[i].get_small_cost() << endl;
		cout << "   m: " << this->coffee_arr[i].get_medium_cost() << endl;
		cout << "   l: " << this->coffee_arr[i].get_large_cost() << endl;
	}
}

/*********************************************************************
** Function: void Menu::update_menu_file() const
** Description: Updates the menu information in the menu.txt file.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The menu information is updated in the menu.txt file.
*********************************************************************/
void Menu::update_menu_file() const {
	// Open menu.txt
	ofstream menu_info("menu.txt");

	// Check if it opens properly
	if (!menu_info.is_open()) {
		cerr << "Error updating menu.txt" << endl;
		return;
	}

	// Set the number of drinks as the first line within the file
	menu_info << this->num_coffee;

	// Sets the rest of the drinks
	for (int i = 0; i < this->num_coffee; ++i) {
		menu_info << endl << this->coffee_arr[i].get_name() << " "
						  << this->coffee_arr[i].get_small_cost() << " "
						  << this->coffee_arr[i].get_medium_cost() << " "
						  << this->coffee_arr[i].get_large_cost();
	}

	// Closes the file
	menu_info.close();
}

/*********************************************************************
** Function: void Menu::add_to_pseudo_menu(Coffee& coffee_to_add)
** Description: Adds a new coffee item to a pseudo menu without updating the actual menu.
** Parameters: coffee_to_add - a reference to the Coffee object to be added to the pseudo menu
** Pre-Conditions: None
** Post-Conditions: The specified Coffee object is added to the pseudo menu.
*********************************************************************/
void Menu::add_to_pseudo_menu(const Coffee& coffee_to_add){
	// Create temp_arr
	Coffee* temp_arr = new Coffee[num_coffee + 1];

	// Move over everything from num_coffee to the temp_arr
	for (int i = 0; i < this->num_coffee; ++i) {
		temp_arr[i] = Coffee(this->coffee_arr[i]);
	}

	// Add new drink to the end of the array
	temp_arr[this->num_coffee] = coffee_to_add;

	// Add new drink on the menu
	++num_coffee;

	// Deallocate coffee_arr
	delete [] coffee_arr;
	this->coffee_arr = NULL;

	// Reallocate it and set it to = temp_arr
	this->coffee_arr = temp_arr;

	return;
}