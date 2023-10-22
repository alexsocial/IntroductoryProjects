/*
Alexander Chaban
Due Date: 10/22/2020
Course:  C0P3014
Assignment:  Program 6
Professor: Sorgente

Description: number guessing game with a random number generator
static array to store game results.

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <ctime> //random number generator
#include <fstream>//output file
using namespace std;

const int NUM_GAMES = 50;
//maximum number of games for the array declaration
/*********************************************************
//Following is the declaration of a round of the guessing game
**********************************************************/
class numberGame
{
public:
	int level = 0;
	int upperRange = 0;
	int maxGuesses = 0;
	int currentGuess = 0;
	int solutionNumber = 0;
	bool guessTooLow = false;
	bool guessTooHigh = false;
	string name; //name of current player
	bool wonOrLost = false; //true or false for the current round of the game
};

//Declaration/ Prototypes for your functions will go here

//BE SURE TO UPDATE the COMMENTS 
//pre and post conditions on the function prototypes
//descriptions on the function definitions 
//comments throughout the code making it easier to read

void LevelRange(numberGame& currentGame);
//Precondition: Takes in a numberGame object that already exists.
//Postcondition: Takes in the upper range (as the lower range is always one), depending on the level.
//Description:  sets the upper range of the current game based on the level

void LevelGuesses(numberGame& currentGame);
//Precondition: Takes in a numberGame object that already exists.
//Postcondition: Takes in the maximum number of guesses based on the level.
//Description:  sets the number of guesses for the current round based on the level

void PlayOneRound(numberGame& currentGame);
//Precondition: Takes in a numberGame object that already exists and a name that already exists and is a constant.
//Postcondition: One round will be completely played, and another will be offered.
//Description:  Play one round of the number guess game

void GetNextGuess(numberGame& currentGame);
//Precondition: Takes in a numberGame object that already exists.
//Postcondition: The next guess will be calculated.
//Description:  get the next guess from the user

bool ProcessGuess(numberGame& currentGame);
//Precondition: Takes in a numberGame object that already exists.
//Postcondition: The guess will be determined based on if it was correct or not, and end the round.
//Description:  returns true if the guess matches the solution
//returns false if they do not match
//lets the user know if the guess was too high or too low

void GenerateRandomNumber(numberGame& currentGame);
//Precondition: Takes in a numberGame object that already exists.
//Postcondition: The game's solution will be generated.
//Description:  Generates the solution number in the correct range

void PrintGameResults(numberGame gameList[], int gameCount);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Connects to an output file
//Prints the array results onto the screen and into the output file


//HERE IS THE main function
int main()
{
	string yesOrNo = "y";

	//declare an array of numberGame
	//count the number of games, initialize to 0 
	numberGame gameList[NUM_GAMES];
	int gameCount = 0;

	cout << "Do you want to play the guessing game? (Q to Quit):  ";
	cin >> yesOrNo;

	while (yesOrNo != "q" && yesOrNo != "Q")
	{
		//ask for the name here, it may be a different player
		cout << "Enter your first name: ";
		//into the member variable name
		cin >> gameList[gameCount].name;
		//call Play one round function
		PlayOneRound(gameList[gameCount]);

		//add one to the gamecount
		gameCount++;
		cout << "Do you want to play the another round? (Q to quit):  ";
		cin >> yesOrNo;

	}
	//Print the game results function call
	PrintGameResults(gameList, gameCount);
	return  0;
}

//Function Implementations will go here

void  LevelRange(numberGame& currentGame)
//Description:  sets the upper range of the current game based on the level
{
	if (currentGame.level == 1)
	{
		currentGame.upperRange = 10;
	}
	else if (currentGame.level == 2)
	{
		currentGame.upperRange = 30;
	}
	else if (currentGame.level == 3)
	{
		currentGame.upperRange = 75;
	}
	else
	{
		cout << "That is not a level, assuming level one." << endl;
		currentGame.upperRange = 10;
	}

	//add the rest of the conditions

}

void  LevelGuesses(numberGame& currentGame)
//Description:  sets the number of guesses for the current round based on the level
{
	if (currentGame.level == 1) currentGame.maxGuesses = 3;
	else if (currentGame.level == 2) currentGame.maxGuesses = 4;
	else currentGame.maxGuesses = 5;
	//add the rest of the conditions
}

void PlayOneRound(numberGame& currentGame)
//Description:  Play one round of the guess game
{
	currentGame.wonOrLost = 0;//REQUIRED, keeps track if the user won or lost the round
	currentGame.guessTooLow = 0;
	currentGame.guessTooHigh = 0;

	//describe the levels to the user
	cout << "What level would you like to play? \n";
	cout << "(1) Level 1 -3 guesses, numbers 1 through 10\n";
	cout << "(2) Level 2 - 4 guesses, numbers 1 through 30\n";
	cout << "(3) Level 3 -5 guesses, numbers 1 through 75: ";
	cin >> currentGame.level;

	//set the upper range based on the level (LevelRange function)
	LevelRange(currentGame);
	//generate the random number
	GenerateRandomNumber(currentGame);

	//set the max guesses based on the level (LevelGuesses function)
	LevelGuesses(currentGame);
	//loop header, counting loop for the number of guesses
	//currentGame.max_guesses)
	for (int i = 1; i < currentGame.maxGuesses + 1; i++)
	{

		//tell the user what guess number they are on
		//get the next guess
		cout << "You are on guess #" << i << "\n";
		GetNextGuess(currentGame);
		//reset above and below to 0
		currentGame.guessTooLow = 0;
		currentGame.guessTooHigh = 0;
		if (ProcessGuess(currentGame))
		{
			cout << "\nYou won that round, " << currentGame.name << "!\n";
			i = currentGame.maxGuesses;
			//Do not use break statement...
		}
	}
	//tell the user the solution after the round of the game is done
	cout << "The solution was " << currentGame.solutionNumber << endl;
}



void GetNextGuess(numberGame& currentGame)
//Description:  get the next guess from the user
{
	if (currentGame.guessTooLow)
	{
		cout << "\nEnter a guess above " << currentGame.currentGuess << " : ";
	}
	else if (currentGame.guessTooHigh)
	{
		cout << "\nEnter a guess below " << currentGame.currentGuess << " : ";
	}
	//add the other conditions
	//get the next guess
	cin >> currentGame.currentGuess;
}

bool ProcessGuess(numberGame& currentGame)
//Description:  returns true if the guess matches the solution
//returns false if they do not match
//lets the user know if the guess was too high or too low
{
	if (currentGame.currentGuess > currentGame.solutionNumber)
	{
		cout << "\nYour guess was too high."; //Guess was too high
		cout << "\n-----------------------\n";
		currentGame.guessTooHigh = true;
		return false;
	}
	else if (currentGame.currentGuess < currentGame.solutionNumber)
	{
		cout << "\nYour guess was too low.";
		cout << "\n-----------------------\n";
		currentGame.guessTooLow = true;
		return false;
	}
	else
	{
		cout << "\nYour guess was correct!";
		cout << "\n-----------------------\n";
		currentGame.guessTooLow = false;
		currentGame.guessTooHigh = false;
		currentGame.wonOrLost = true;
		return true;

	}

}

void GenerateRandomNumber(numberGame& currentGame)
//Description:  Generates the solution number in the correct range
{
	srand((unsigned)time(0));
	currentGame.solutionNumber = 1 + rand() % currentGame.upperRange;
	//cout << "\nSolution is " << currentGame.solutionNumber << endl;
}


void PrintGameResults(numberGame gameList[], int gameCount)
//Description: prints the information in the array on the screen and into an output file
//the name, level, and whether or not they won or lost that round
{
	ofstream out;
	//open the output file
	out.open("numberGameResults.txt");
	cout << "\n***********************************\n";
	cout << "Name\t" << "Level\t" << "won or lost\n";
	//use a loop to print the array (name, level, WonOrLost) onto the screen
	for (int i = 0; i < gameCount; i++)
	{
		if (gameList[i].wonOrLost == true)
			cout << gameList[i].name << "\t" << gameList[i].level << "\t" << "won" << endl;
		else
			cout << gameList[i].name << "\t" << gameList[i].level << "\t" << "lost" << endl;
	}
	out << "\n***********************************\n";
	out << "Name\t" << "Level\t" << "won or lost\n";
	//use a loop to print the array (name, level, WonOrLost) into the file
	for (int i = 0; i < gameCount; i++)
	{
		if (gameList[i].wonOrLost == true)
			out << gameList[i].name << "\t" << gameList[i].level << "\t" << "won" << endl;
		else
			out << gameList[i].name << "\t" << gameList[i].level << "\t" << "lost" << endl;
	}
	//close the file
	out.close();
}


