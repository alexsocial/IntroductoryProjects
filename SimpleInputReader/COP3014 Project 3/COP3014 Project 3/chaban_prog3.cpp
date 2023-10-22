/****SAMPLE PROGRAM HEADER*******************************************************
Name: Alexander Chaban
Due Date : September 22nd, 2020
Course:  C0P3014
Assignment : Program 3
Professor : Sorgente
Description: Create a program that calculates the total cost including net cost and tax of an online order using functions
gathering info for it from an input file.

*************************************************************/
#include <iostream> //standard library for i/o
#include <fstream>//you must include this library if you wish to do file i/o
#include <string> // always include this when you use the string class

using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
struct orderRecord
{
	string cellNum;
	string itemNum;
	int quantity = 0;
	double price = 0.0;
	int locationID = 0;
	double taxRate = 0.0;
	double tax = 0.0;
	double netCost = 0.0;
	double totalCost = 0.0;
};

//Declaration/ Prototypes for your functions will go here
//BE SURE TO ADD COMMENTS TO THE FUNCTION PROTOTYPES AND THE FUNCTION DEFINITIONS

void DataFromFile(ifstream&, orderRecord&);
//Precondition: Takes in a file and the structure that is already defined.
//Postcondition: The file with the order info, and stores it.
//Description:  Takes in the data from the file.

void PrintToScreen(const orderRecord&);
//Precondition: Takes in an already existing order record file.
//Postcondition: The results are correctly printed to the screen.
//Description:  Prints the results to the screen.

void ProcessData(orderRecord&);
//Precondition: Takes in one struct that already exists. Requires GetTaxRate function.
//Postcondition: The data is processed, and everything is calculated.
//Description:  Processes the data of each order.

void GetTaxRate(double&, int);
//Precondition: Takes in one double that exists as a variable and one integer.
//Postcondition: The tax rate will be calculated and the location ID is stored.
//Description:  Calculates the tax rate based on the location ID.

int main()
{
	string name;
	cout << "Enter your first name: ";
	cin >> name;
	cout << name << ", Let's get started processing the file data." << endl;

	orderRecord recordData;

	ifstream in;    //declaring an input file stream
	in.open("inputData.txt"); //connect to the input file add the file name

	if (in.fail())
	{
		cout << "Input file did not open correctly\n" << endl; //Reports if the file isn't correct.
	}
	else
	{
		cout << "Connected to the input file\n" << endl;
		while (!in.eof()) //has not reached the end of the file
		{
			DataFromFile(in, recordData);
			ProcessData(recordData);
			PrintToScreen(recordData);
		}
	}

	in.close();
	//say goodbye to the user
	cout << name << ", have a nice day!" << endl;
	return 0;
}


//Function Implementations will go here

void DataFromFile(ifstream& in, orderRecord& currentRecord)
//Description:  Takes in the data from the file.
{
	in >> currentRecord.cellNum;
	in >> currentRecord.itemNum;
	in >> currentRecord.quantity;
	in >> currentRecord.price;
	in >> currentRecord.locationID;
	//add more code to read the rest of the fields 
	//(itemNum, quantity, price and locationID) 
	//into the order record, currentRecord.
}

void ProcessData(orderRecord& currentRecord)
//Description:  Get the tax rate and calculate the rest of the unknowns.
{

	//Call the GetTaxRate function to get the tax rate 
	//based on the currentRecord.locationID
	//calculate the tax, netCost, and totalCost
	//of the currentRecord, example: currentRecord.taxRate
	GetTaxRate(currentRecord.taxRate, currentRecord.locationID);
	currentRecord.tax = currentRecord.price * currentRecord.taxRate * currentRecord.quantity;
	currentRecord.netCost = currentRecord.quantity * currentRecord.price;
	currentRecord.totalCost = currentRecord.netCost + currentRecord.tax;
}

void GetTaxRate(double& taxRate, int locationID)
//Description:  Gets the rate of tax based on the location ID.
{
	//use the location ID to set the tax rate
	if (0 <= locationID && locationID <= 50)
	{
		taxRate = .0400; //4% of price
	}
	else if (51 <= locationID && locationID <= 80)
	{
		taxRate = .0525; //5.25% of price
	}
	else if (81 <= locationID && locationID <= 100)
	{
		taxRate = .0600; //6% of price
	}
	else
	{
		taxRate = .0725; //7.25% of price
	}
}

void PrintToScreen(const orderRecord& currentRecord)
//Description:  Prints the results to the screen.
{
	//set the number of decimal places for doubles
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2); //use any number her for the number of decimal places

	// display the results here
	//add more code to print all the fields in the order record

	cout << currentRecord.cellNum << "\t";
	cout << currentRecord.itemNum << "\t";
	cout << currentRecord.quantity << "\t";
	cout << currentRecord.price << "\t";
	cout << currentRecord.locationID << "\t";

	cout.precision(4);//4 decimal places
	cout << currentRecord.taxRate << "\t";

	cout.precision(2);//back to 2 decimal places
	cout << currentRecord.tax << "\t";
	cout << currentRecord.netCost << "\t";
	cout << currentRecord.totalCost << "\t" << endl;

}


