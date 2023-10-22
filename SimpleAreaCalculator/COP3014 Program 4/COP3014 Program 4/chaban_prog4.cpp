
/****SAMPLE PROGRAM HEADER*******************************************************
Student Name: Alexander Chaban
Due Date: 9/29/2020
Course:  C0P3014
Assignment:  Program 4
Professor: Sorgente

Description: area and perimeter calculator

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <cmath> //for sqrt

using namespace std;

//add function prototypes here 
//Be sure to include pre and post conditions and a brief description

void MenuChoices(string name, string& quit);
//Precondition: Takes in a non-editable string and an editable string.
//Postcondition:  The menu will be navigated/chosen.
//Description: Navigates through the menu.

void ProcessChoice(string& quit, double& area, double& perimeter);
//Precondition: Takes in a string and two doubles that already exist.
//Postcondition: The area and perimeter will be calculated, and the program will finish if chosen to quit.
//Description: Takes in the choice of the user, and calculates the area/perimeter, if they put an acceptable choice.

//HERE IS THE main function, DO NOT MODIFY THE MAIN FUNCTION

int main()
{
	double area = 0.0;
	double perimeter = 0.0;
	string quit;
	string name;
	cout << "Welcome to the area and perimeter calculator, what is your first name? ";
	cin >> name;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3); //display the area to 3 decimal places

	MenuChoices(name, quit);
	ProcessChoice(quit, area, perimeter);

	while (quit != "Q" && quit != "q")
	{

		cout.precision(3); //display the area to 3 decimal places
		cout << "\nThe area (displayed in the main function) is " << area << endl;
		cout << "\nThe perimeter (displayed in the main function) is " << perimeter << endl;

		MenuChoices(name, quit);
		ProcessChoice(quit, area, perimeter);
	}
	cout << "\nGoodbye " << name << ", Have a great day! ";
	return 0;
}


//add function definitions here 
//Be sure to include a brief description
void MenuChoices(string name, string& quit)
//Description: Navigates through the menu.
{
	cout << "---------------------------------------------------\n";
	cout << name << ", please enter a T, R, or Q. \n";
	cout << "To calculate: \n";
	cout << "The Area and Perimeter of a trinagle, enter T\n";
	cout << "The Area and Perimeter of a rectangle, enter R\n";
	cout << "---------------------------------------------------\n" << endl;
}

void ProcessChoice(string& quit, double& area, double& perimeter)
//Description: Takes in the choice of the user, and calculates the area/perimeter, if they put an acceptable choice.
{
	cout << "Enter Q to quit: ";
	cin >> quit;
	if (quit == "T" || quit == "t")
	{
		//Checks if it is a triangle
		double triSideOne;
		double triSideTwo;
		double triSideThree;
		double semiperimeter;
		cout << "Please enter side one: ";
		cin >> triSideOne;
		cout << "Please enter side two: ";
		cin >> triSideTwo; 
		cout << "Please enter side three: ";
		cin >> triSideThree; //Gets user input for sides
		if ((triSideOne + triSideTwo < triSideThree) || (triSideOne + triSideThree < triSideTwo) || (triSideTwo + triSideThree < triSideOne))
		{ //Basically this giant if checks if the sum of two sides is smaller than one of the sides via process of elimation.
			cout << "Not a valid triangle." << endl;
			area = 0;
			perimeter = 0;
		}
		else
		{
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(1); //display the area to 1 decimal place
			cout << "Side A\t Side B\t Side C\n";
			cout << triSideOne << "\t" << triSideTwo << "\t" << triSideThree << endl;
			cout << "---------------------------------------------------\n"; //Displays sides
			semiperimeter = (triSideOne + triSideTwo + triSideThree) / 2;
			perimeter = semiperimeter * 2;
			area = sqrt(semiperimeter * (semiperimeter - triSideOne) * (semiperimeter - triSideTwo) * (semiperimeter - triSideThree));
			//Calculates Results
		}
	}
	else if (quit == "R" || quit == "r")
	{
		//Checks if it is a rectangle
		double recSideOne;
		double recSideTwo;
		cout << "Please enter side one: ";
		cin >> recSideOne;
		cout << "Please enter side two: ";
		cin >> recSideTwo; //Gets user input for sides
		cout << "Side X \t Side Y\n";
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(1); //display the area to 1 decimal place
		cout << recSideOne << "\t" << recSideTwo << endl;
		cout << "---------------------------------------------------\n";
		area = recSideOne * recSideTwo; //Performs calculations
		perimeter = recSideOne * 2 + recSideTwo * 2;
	}
	else if (quit == "Q" || quit == "q")
	{
		//Blank line to end it. For some reason it'll still display the area and perimeter.
	}
	else 
	{
		cout << "That input is not recognized." << endl;
		area = 0;
		perimeter = 0;
	}
}