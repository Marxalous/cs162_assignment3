#ifndef ORDER_H
#define ORDER_H 

#include <string>

using namespace std;

class Order {
  private:
    int id; // ID number for the order
    string coffee_name; // The name of the type of coffee ordered
    char coffee_size; // The size of the coffee ordered
    int quantity; // The quantity of drinks on the coffee order

  public:
    Order(); // Default constructor for the Order class
    Order(int, string, char, int); // Non-default constructor for the Order class

    void set_id(const int id); // Setter function for the order ID
    void set_coffee_name(const string coffee_name); // Setter function for the coffee name in the order
    void set_coffee_size(const char coffee_size); // Setter function for the coffee size in the order
    void set_quantity(const int quantity); // Setter function for the quantity of coffee in the order

    int get_id() const; // Getter function for the order ID
    string get_coffee_name() const; // Getter function for the coffee name in the order
    char get_coffee_size() const; // Getter function for the coffee size in the order
    int get_quantity() const; // Getter function for the quantity of coffee in the order
};

#endif