#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Declare prototype
int binarySearch(string[], int, string);

/*---------------------------------------------------------------------------------------------------------------------------------------------
	The is the main function for this class.  It prompts the user to enter an anminal. If the user doesn't enter a correct animal
	from the array, then it will prompt the user to enter the information again.  Finally, if all the information is correct, then
	the information is outputted to the screen.
----------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
	//Declare local variables
	const int NUM_NAMES = 10;
	string names[NUM_NAMES] = { "baboon", "giraffe", "hippopotamus", "lion", "monkey", "rhinoceros", "tapir", "tiger", "wildebeest", "zebra" };
	string enteredValue;
	int returnedValue;
	bool found = true;

	//Ask the user to enter an animal
	cout << "Please enter an animal that you would like to search: ";
	cin >> enteredValue;
	
	//Call the search function
	returnedValue = binarySearch(names, NUM_NAMES, enteredValue);

	//Check to see if the user entered the correct information, and output correct messages to the terminal
	if (returnedValue == -1) {
		while (found) {
			cout << "The entered value was not found. Please try again." << endl;
			cout << "Please enter an animal that you would like to search: ";
			cin >> enteredValue;
			returnedValue = binarySearch(names, NUM_NAMES, enteredValue);
			if (returnedValue > -1) {
				cout << "The entered animal was found a position: " << returnedValue + 1 << endl;
				break;
			}
		}
	}
	else if (returnedValue > -1) {
		cout << "The entered animal was found a position: " << returnedValue + 1 << endl;
	}
	return 0;
}


/*---------------------------------------------------------------------------------------------------------------------
	This function accepts a string array, the size of the array, and a string all as parameters.  It takes the string
	value and searches through the array to find its positon.  The value is then returned.
----------------------------------------------------------------------------------------------------------------------*/
int binarySearch(string array[], int size, string value)
{
	int first = 0,             // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;        // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point
		if (array[middle] == value) {      // If value is found at mid
			found = true;
			position = middle;
		} else if (array[middle] > value) {  // If value is in lower half
			last = middle - 1;
		} else {
			first = middle + 1;           // If value is in upper half
		}
	} 
	return position;
}


