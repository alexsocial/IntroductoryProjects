// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/******** 
Name: Alexander Chaban
Due Date : September 8th, 2020
Course:  C0P3014
Assignment : Program 1
Professor : Sorgente 
Purpose of assignment: Create a program that calculates the total cost including net cost and tax of an online order.
********/


#include <iostream>
#include <string>

using namespace std;


int main()
{
	string userResponse = "y";
	string name;
	string cellNumber;
	string itemNumber;
	int quantity;
	double price;
	double tax;
	double netCost;
	double totalCost;
	int locationID;
	double taxRate;

	cout << "Enter your first name: ";
	cin >> name;


	while (userResponse != "n" && userResponse != "N")
	{
		//The code to get the user's input, perform the calculations, and print
		// the results to the screen should go here. 

		cout << name << ", please enter your cell phone number: " << endl;
		cin >> cellNumber;

		cout << name << ", please enter the item number: " << endl;
		cin >> itemNumber;

		cout << name << ", please enter the quantity: " << endl;
		cin >> quantity;

		cout << name << ", please enter the price: " << endl;
		cin >> price;

		cout << name << ", please enter the location ID number: " << endl;
		cin >> locationID;
		//Gathers inputs

		if (locationID < 0) //Checks first to see if locationID is a valid number
		{
			cout << "A negative number for the location ID is not a valid entry." << endl;
			taxRate = 0;
			price = 0;
			tax = 0;
			netCost = 0;
			totalCost = 0;
		}
		//Sets everything to zero if it is not a valid ID number.
		else if (0 <= locationID && locationID <= 50)
		{
			taxRate = .04; //4% of price
		}
		else if (51 <= locationID && locationID <= 80)
		{
			taxRate = .0525; //5.25% of price
		}
		else if (81 <= locationID && locationID <= 100)
		{
			taxRate = .06; //6% of price
		}
		else
		{
			taxRate = .0725; //7.25% of price
		}

		//Calculations
		tax = quantity * price * taxRate;
		netCost = quantity * price;
		totalCost = netCost + tax; 

		//set the number of decimal places for doubles “magic formula”
		cout.setf(ios::fixed); //not written in e-notation
		cout.setf(ios::showpoint);//displaythe decimal point
		cout.precision(2); //use any number her for the number of decimal places

		cout << "Cell number: " << cellNumber << endl;
		cout << "Item number: " << itemNumber << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Price: $" << price << endl;
		cout << "Tax rate: " << taxRate * 100 << "%" << endl;
		cout << "Tax: $" << tax << endl;
		cout << "Net cost: $" << netCost << endl;
		cout << "Cell number: $" << totalCost << endl;
		//Displays all data

		cout << name << ", would you like to do another calculation (Y or N): " << endl;
		cin >> userResponse;

		//Asks the user if they want to go again
		
		cout << "\n\n" << endl; //Spacing purposes
	}
	cout << name << ", thank you for your puchase(s). Have a nice day!" << endl;
	return  0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
