#ifndef MENU_H
#define MENU_H 

#include "coffee.h"

using namespace std;

class Menu {
  private:
    int num_coffee; // Number of drinks in coffee_arr
    Coffee* coffee_arr; // Array of coffee

  public:
    Menu(); // Default constructor for the Menu class
    Menu(int); // Non-default constructor for the Menu class

    ~Menu(); // Destructor for the Menu class
    Menu(const Menu&); // Copy constructor for the Menu class
    Menu& operator=(const Menu&); // Assignment operator for the Menu class

    Coffee search_coffee_by_name(const string name); // Searches for a coffee item in the menu by its name
    Menu search_coffee_by_price(const float budget); // Searches for coffee items in the menu with a cost equal to or lower than the specified budget
    void add_to_menu(const Coffee& coffee_to_add); // Adds a new coffee item to the menu
    void remove_from_menu(const int index_of_coffee_on_menu); // Removes a coffee item from the menu at the specified index

    void set_coffee_arr(const Coffee* temp_arr, int num_coffee); // Sets the coffee array of the menu to the specified array and size
    Coffee* get_coffee_arr() const; // Getter function to retrieve the coffee array of the menu
    int get_num_coffee() const; // Getter function to retrieve the number of coffee items in the menu
    void print_menu() const; // Prints the details of each coffee item in the menu
    void update_menu_file() const; // Updates the menu information in the menu.txt file
    void add_to_pseudo_menu(const Coffee& coffee_to_add); // Adds a new coffee item to a pseudo menu without updating the actual menu
};

#endif