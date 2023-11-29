/*********************************************************************
** Program Filename: order.cpp
** Author: Matthew McMahon
** Date: 11/12/2023
** Description: cpp file that contains the functions for the Order class
** Input: order.h
** Output: functions for the class Order
*********************************************************************/

#include "order.h"

#include <string>
#include <iostream>

using namespace std;

/*********************************************************************
** Function: Order::Order()
** Description: Default constructor for the Order class.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Initializes order attributes with default values.
*********************************************************************/
Order::Order() {
    this->id = 0;
    this->coffee_name = "";
    this->coffee_size = ' ';
    this->quantity = 0;
}

/*********************************************************************
** Function: Order::Order(int id, string coffee_name, char coffee_size, int quantity)
** Description: Non-Default constructor for the Order class.
** Parameters: 
**   - id: Order ID
**   - coffee_name: Name of the coffee in the order
**   - coffee_size: Size of the coffee in the order
**   - quantity: Quantity of the coffee in the order
** Pre-Conditions: None
** Post-Conditions: Initializes order attributes with the provided values.
*********************************************************************/
Order::Order(int id, string coffee_name, char coffee_size, int quantity) {
    this->id = id;
    this->coffee_name = coffee_name;
    this->coffee_size = coffee_size;
    this->quantity = quantity;
}

void Order::set_id(const int id) {
    this->id = id;
}

void Order::set_coffee_name(const string coffee_name) {
    this->coffee_name = coffee_name;
}

void Order::set_coffee_size(const char coffee_size) {
    this->coffee_size = coffee_size;
}

void Order::set_quantity(const int quantity) {
    this->quantity = quantity;
}

/*********************************************************************
** Function: int Order::get_id() const
** Description: Getter function for the order ID.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the order ID.
*********************************************************************/
int Order::get_id() const {
    return this->id;
}

/*********************************************************************
** Function: string Order::get_coffee_name() const
** Description: Getter function for the coffee name in the order.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the coffee name.
*********************************************************************/
string Order::get_coffee_name() const {
    return this->coffee_name;
}

/*********************************************************************
** Function: char Order::get_coffee_size() const
** Description: Getter function for the coffee size in the order.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the coffee size.
*********************************************************************/
char Order::get_coffee_size() const {
    return this->coffee_size;
}

/*********************************************************************
** Function: int Order::get_quantity() const
** Description: Getter function for the quantity of coffee in the order.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns the quantity of coffee.
*********************************************************************/
int Order::get_quantity() const {
    return this->quantity;
}