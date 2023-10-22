// COP3014 Program 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/********
Name: Alexander Chaban
Due Date : September 16th, 2020
Course:  C0P3014
Assignment : Program 2
Professor : Sorgente
Description: Create a program that calculates the total cost including net cost and tax of an online order using functions.
********/

#include <iostream>
#include <string>
using namespace std;

//Declaration/ Prototypes for your functions will go here
//BE SURE TO UPDATE the Comments in THE FUNCTION PROTOTYPES AND THE FUNCTION DEFINITIONS

void GetOrderInfo(string&, string&, int&, double&, int&);
//Precondition: Must have 2 strings, 2 integers, and one double that already exist as variables.
//Postcondition: The order values will be stored into their appropriate variables.
//Description:  Gets the order.

void GetTaxRate(double&, int);
//Precondition: Takes in one double that exists as a variable and one integer.
//Postcondition: The tax rate will be calculated and the location ID is stored.
//Description:  Calculates the tax rate based on the location ID.

void CalculateResults(int, double, double, double&, double&, double&);
//Precondition: Takes in one integer, two doubles, and three doubles that already exist.
//Postcondition: The tax, net cost, and total cost will be calculated and used for the DisplayResults function.
//Description:  Calculates the tax, net cost, and total cost.

void DisplayResults(string, string, int, double, int, double, double, double, double);
//Precondition: Takes in two strings, two ints, and four doubles.
//Postcondition: Every variable will be displayed as a result based on previous functions.
//Description:  Displays the entire order's stats.


//HERE IS THE main function

int main()
{
	string userResponse = "y";
	string name;
	cout << "Enter your first name: ";
	cin >> name;
	string cellNum;
	string itemNum;
	int quantity;
	double price;
	double tax;
	double netCost;
	double totalCost;
	int locationID;
	double taxRate;
	//declare all variables in the main function 
	//to practice pass by reference and pass by value

	while (userResponse != "n" && userResponse != "N")
	{
		//get the order data function call
		GetOrderInfo(cellNum, itemNum, quantity, price, locationID);

		if (locationID < 0) //invalid location
			cout << "invalid location \n";
		else
		{
			//get the tax rate function call
			GetTaxRate(taxRate, locationID);
			//make the calculations function call
			CalculateResults(quantity, price, taxRate, tax, netCost, totalCost);
			//display the results function call
			DisplayResults(cellNum, itemNum, quantity, price, locationID, taxRate, tax, netCost, totalCost);

		}
		cout << name << ", Would you like to do another calculation (Y or N): " << endl;
		cin >> userResponse;
	}
	return  0;
}

//Function Implementations will go here

//Description:  Sets the the tax rate by reference based on the value of the location ID
//*************************************************************************************

void GetTaxRate(double& taxRate, int locID)
{
	//use the location ID to set the tax rate
	if (0 <= locID && locID <= 50)
		{
		taxRate = .04; //4% of price
		}
	else if (51 <= locID && locID <= 80)
		{
		taxRate = .0525; //5.25% of price
		}
	else if (81 <= locID && locID <= 100)
		{
		taxRate = .06; //6% of price
		}
	else
		{
		taxRate = .0725; //7.25% of price
		}
}

///*************************************************************************************
//Description:  Describe what the function does (purpose).  
//PURPOSE: SHOW THAT YOU KNOW HOW TO READ INPUT AND USE CALL BY REFERENCE Parameters
//*************************************************************************************

void GetOrderInfo(string& cellNum, string& itemNum, int& quantity, double& price, int& locID)
{
	//ask and get the information from the user
	cout << "Enter the cell phone number: ";
	cin >> cellNum;
	cout << "Enter the item number: ";
	cin >> itemNum;
	cout << "Enter the quantity: ";
	cin >> quantity;
	cout << "Enter the price: ";
	cin >> price;
	cout << "Enter the location ID: ";
	cin >> locID;

}


///*************************************************************************************
//Description:  Calculates the tax, net cost, and total cost.
//PURPOSE: 
// Before calling example: quantity = 10, price = 10, taxRate = .0525
// After calling example: quantity = 10, price = 10, taxRate = .0525, tax = 5.25, net = 100, total = 105.25
///*************************************************************************************
void CalculateResults(int quantity, double price, double taxRate, double& tax, double& net, double& total)
{

	//do the calculations here for tax, net, and total
	tax = quantity * price * taxRate;
	net = quantity * price;
	total = net + tax;

}



///*************************************************************************************
//Description:  Prints the order's stats, price, and net cost.
//PURPOSE: 
// Before calling example: cel/item = <string of persons choice>, quantity = 10, price = 10, locID = 0, taxRate = 0,
// tax = 4.00, net = 100, total = 104.00
//After calling example: cel = 999-999-9999, item = qwAs-rqwst123, quantity = 10, price = 10.00, locID = 0, tax = 4.00,
// net = 100.00, total = 104.00 (changes decimal places to 2)
///*************************************************************************************
void DisplayResults(string cel, string item, int quantity, double price, int locID, double taxRate, double tax, double net, double total)
{

	//set the number of decimal places for doubles
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2); //use any number her for the number of decimal places

	// display the results here
	cout << "Cell number: " << cel << endl;
	cout << "Item number: " << item << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Price: $" << price << endl;
	cout << "Tax rate: " << taxRate * 100 << "%" << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Net cost: $" << net << endl;
	cout << "Total Cost: $" << total << endl;
	//Displays all data


}

