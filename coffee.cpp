/*********************************************************************
** Program Filename: coffee.cpp
** Author: Matthew McMahon
** Date: 11/12/2023
** Description: cpp file that contains the functions for the Coffee class
** Input: coffee.h
** Output: functions for the class Coffee
*********************************************************************/

#include "coffee.h"
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
** Function: Coffee::Coffee()
** Description: Default constructor for the Coffee class. Initializes the name, small, medium, and large costs of the coffee to default values.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: A Coffee object is created with default values.
*********************************************************************/
Coffee::Coffee() {
    this->name = "";
    this->small_cost = 0;
    this->medium_cost = 0;
    this->large_cost = 0;
}

/*********************************************************************
** Function: void Coffee::set_name(const string coffee_name)
** Description: Setter function to set the name of the coffee.
** Parameters: coffee_name - a string representing the name of the coffee
** Pre-Conditions: None
** Post-Conditions: The name of the coffee is set.
*********************************************************************/
void Coffee::set_name(const string coffee_name) {
    this->name = coffee_name;
}

/*********************************************************************
** Function: void Coffee::set_small_cost(const float cost)
** Description: Setter function to set the small cost of the coffee.
** Parameters: cost - a float representing the small cost of the coffee
** Pre-Conditions: None
** Post-Conditions: The small cost of the coffee is set.
*********************************************************************/
void Coffee::set_small_cost(const float cost) {
    this->small_cost = cost;
}

/*********************************************************************
** Function: void Coffee::set_medium_cost(const float cost)
** Description: Setter function to set the medium cost of the coffee.
** Parameters: cost - a float representing the medium cost of the coffee
** Pre-Conditions: None
** Post-Conditions: The medium cost of the coffee is set.
*********************************************************************/
void Coffee::set_medium_cost(const float cost) {
    this->medium_cost = cost;
}

/*********************************************************************
** Function: void Coffee::set_large_cost(const float cost)
** Description: Setter function to set the large cost of the coffee.
** Parameters: cost - a float representing the large cost of the coffee
** Pre-Conditions: None
** Post-Conditions: The large cost of the coffee is set.
*********************************************************************/
void Coffee::set_large_cost(const float cost) {
    this->large_cost = cost;
}

/*********************************************************************
** Function: string Coffee::get_name() const
** Description: Getter function to retrieve the name of the coffee.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The name of the coffee is returned.
*********************************************************************/
string Coffee::get_name() const {
    return this->name;
}

/*********************************************************************
** Function: float Coffee::get_small_cost() const
** Description: Getter function to retrieve the small cost of the coffee.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The small cost of the coffee is returned.
*********************************************************************/
float Coffee::get_small_cost() const {
    return this->small_cost;
}

/*********************************************************************
** Function: float Coffee::get_medium_cost() const
** Description: Getter function to retrieve the medium cost of the coffee.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The medium cost of the coffee is returned.
*********************************************************************/
float Coffee::get_medium_cost() const {
    return this->medium_cost;
}

/*********************************************************************
** Function: float Coffee::get_large_cost() const
** Description: Getter function to retrieve the large cost of the coffee.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: The large cost of the coffee is returned.
*********************************************************************/
float Coffee::get_large_cost() const {
    return this->large_cost;
}