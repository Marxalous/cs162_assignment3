#ifndef COFFEE_H
#define COFFEE_H

#include <string>

using namespace std;

class Coffee {
  private:
    string name; // Coffee name
    float small_cost; // Price of small coffee
    float medium_cost; // Price of medium coffee
    float large_cost; // Price of large coffee
    
  public:
    Coffee(); // Default constructor for the Coffee class

    void set_name(const string); // Setter function to set the name of the coffee
    void set_small_cost(const float); // Setter function to set the small cost of the coffee
    void set_medium_cost(const float); // Setter function to set the medium cost of the coffee
    void set_large_cost(const float); // Setter function to set the large cost of the coffee

    string get_name() const; // Getter function to retrieve the name of the coffee
    float get_small_cost() const; // Getter function to retrieve the small cost of the coffee
    float get_medium_cost() const; // Getter function to retrieve the medium cost of the coffee
    float get_large_cost() const; // Getter function to retrieve the large cost of the coffee
};

#endif