#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
  private:
    Menu m; // Menu object within shop object
    string phone; // Phone number for shop
    string address; // Address for shop
    float revenue; // Shop revenue
    Order *order_arr; // Array of orders
    int num_orders; // Number of orders

  public:
    Shop(); // Default constructor for Shop class
    Shop(string, string, float, int); // Non-default constructor for Shop class

    ~Shop(); // Destructor for Shop class
    Shop(const Shop&); // Copy constructor for Shop class
    Shop& operator=(const Shop& s); // Assignment operator for Shop class

    void set_phone(const string& phone); // Setter function for phone number
    void set_address(const string& address); // Setter function for address
    void set_revenue(float revenue); // Setter function for revenue
    void set_num_orders(int num_orders); // Setter function for number of orders

    string get_phone() const; // Getter function for phone number
    string get_address() const; // Getter function for address
    float get_revenue() const; // Getter function for revenue
    int get_num_orders() const; // Getter function for number of orders

    void load_data(); // Load data for the shop (shop_info.txt, menu.txt, orders.txt)
    void add_revenue_and_orders(); // Initialize revenue and orders in shop_info.txt
    void make_shop_info(); // Read shop information from shop_info.txt
    void make_menu_info(); // Read menu information from menu.txt
    void make_order_info(); // Read order information from orders.txt
    
    void view_shop_detail(); // Display details of the shop and its menu
    void add_to_menu(); // Add a new drink to the menu
    void remove_from_menu(); // Remove a drink from the menu
    void search_by_name(); // Searches for a drink in the menu by name and displays its details
    void search_by_price(); // Searches for drinks within a budget and displays their names and prices
    void place_order(); // Places an order by taking user input for drink, size, and quantity
    void order_place(Order& order_to_add); // Places an order by adding it to the order list and updating the order file
    void update_order_file() const; // Writes to orders.txt

    Shop clone_shop(); // Creates and returns a clone of the current Shop object
};

#endif