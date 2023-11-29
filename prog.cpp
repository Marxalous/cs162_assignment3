/*********************************************************************
** Program Filename: prog.cpp
** Author: Matthew McMahon
** Date: 11/12/2023
** Description: cpp file that contains int main()
** Input: None
** Output: The program
*********************************************************************/

#include <iostream>
#include "display.h"

using namespace std;


int main() {
	// Start of program
	cout << "Welcome to\n"
		    "   ____       __  __                       \n"
            "  / ___|___  / _|/ _| ___  ___   _     _   \n"
		    " | |   / _ \\| |_| |_ / _ \\/ _ \\_| |_ _| |_ \n"
		    " | |__| (_) |  _|  _|  __/  __/_   _|_   _|\n"
		    "  \\____\\___/|_| |_|  \\___|\\___| |_|   |_|  \n";

	// Creates the shop 's'
	Shop s;
	
	// Populate the shop's data
	s.load_data();

	// Display loop
	int choice = -1;
	while (choice != QUIT){
		choice = get_choice();
		perform_action(s, choice);
	}
	
	// Exit of the program
	cout << "\nShutting down..." << endl;
	return 0;
}