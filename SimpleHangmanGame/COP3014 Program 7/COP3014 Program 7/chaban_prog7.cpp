//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT

/****SAMPLE PROGRAM HEADER*******************************************************
Alexander Chaban
Due Date: 11/6/2020
Course:  C0P3014
Assignment:  Program 7
Professor: Sorgente

Description: hangman game

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <fstream> //file input/ output
#include <cstdlib> //for exit()

using namespace std;

const int numGuesses = 6;//six guesses (head, body, arm1, arm2, leg1, leg2

/*********************************************************
//Following is the declaration of a round of the hangman game
**********************************************************/
class hangmanGame
{
public:
	string solution; //solution word
	string userGuess; //if the user guesses a correct letter they can guess the word
	char hintWord[20] = "";//hint word made of *
	char lettersGuessed[20] = "";//letters guessed so far (right or wrong)
	int letterCount = 0;//number of letters guessed so far (right or wrong)
	int incorrectCount = 0;//number of incorrect letters guessed so far
	char currentLetter = ' ';//current letter guess
	int wordLength = 0;//length of the solution word
	bool correctLetter = false;//flag to set if the letter is in the word
	bool win = false;//flag to set if all the user won that round
};


//Declaration/ Prototypes for your functions will go here
//BE SURE TO ADD COMMENTS TO THE FUNCTION PROTOTYPES AND THE FUNCTION DEFINITIONS

void HangmanRules(const string&);
//Description:  provides instructions to the user on how to play the game

void SetUpOneRound(hangmanGame&, ifstream&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Get the word from the file and reset all member variables

void CreateHintWord(hangmanGame&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  creates the array of *

void PlayHangman(const string&, hangmanGame&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Play one round of the hangman game

void GetLetterGuess(hangmanGame&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Displays hint array and letters guessed asks and gets a current letter guess from 
//the user and adds it to the letters guessed array

bool InterpretLetterGuess(hangmanGame&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Check if the letter guessed is in the solution and if it is, replace all * with that 
//letter in the hintWord and return true, otherwise return false

void CorrectGuess(hangmanGame&, string name);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  checks for the final correct letter and if it is not the final correct letter
//ask and get a word guess from the user if the user wants to guess the word 

bool GameOver(const hangmanGame&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  This function will return true if the hintWord matches the solution, you can use ==  
//or if the userGuess matches the solution, you can use ==

void WonOrLostDisplay(const hangmanGame&, string name);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description: Lets the user know if they won or lost the round

void DrawHangman(hangmanGame&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Draw or describe the hangman drawing

//HERE IS THE main function, a driver to test your program

int main()
{
	//declare variables
	//name, y or n, file, hangman game object 
	ifstream in;

	//connect to the input file 
	in.open("inputWords.txt");
	//if file did not open correctly
	if(in.fail())
	{
		cout << "Input file did not open correctly" << endl;
		exit(1);
	}
	string name;
	hangmanGame activeGame;
	string again;
	//ask and get the users name
	cout << "Enter your name: ";
	cin >> name;
	//Hangman rules
	HangmanRules(name);
	//ask and get yes or no if the user wants to play
	cout << "Do you want to play? (Y or N): ";
	cin >> again;
	//loop to continue to play another round
	{
		while (again == "Y" || again == "y")
		{


			//set up the hangman round
			SetUpOneRound(activeGame, in);
			//play one round of hangman
			PlayHangman(name, activeGame);

			cout << "Do you want to play again? (Y or N): ";
			cin >> again;
			//again?
		}
	}

	return  0;
}

//Function Implementations will go here

void HangmanRules(const string& name)
//Description:  provides instructions to the user on how to play the game
{
	//greets user and prints rules
	cout << endl << "                         " << name << ", Welcome to Hangman.\n\n";
	cout << " \n";
	cout << "\tPlease read the following rules before playing. \n\n";
	cout << "\t 1. You'll be presented with a word. Guess it. \n";
	cout << "\t 2. Guess letters one at a time. \n";
	cout << "\t 3. You can only have up to SIX(6) incorrect letters. \n";
	cout << "\t 4. You can only guess the word once you've guessed ONE correct letter.\n";
	cout << "\t 5. Game over when you guess the word correctly, or if guessed incorrectly six times.\n\n";
	cout << "\t 6. Have fun.		\n";
}

void SetUpOneRound(hangmanGame& activeGame, ifstream& in)
//Description:  Get the word from the file and reset all member variables
{

	activeGame.solution = "";//clear the solution word
	//clear userGuess string
	activeGame.userGuess = "";
	activeGame.hintWord[0] = '\0'; //clear the star array  
	//clear the lettersGuessed array
	activeGame.lettersGuessed[0] = '\0';
	activeGame.letterCount = 0; //letter count starts back at 0
	//reset the incorrectCount
	activeGame.incorrectCount = 0;
	activeGame.correctLetter = false; //reset correctLetter to false
	//reset win to false
	activeGame.win = false;

	//get a word form the file
	in >> activeGame.solution;

	//create the hint word
	CreateHintWord(activeGame);
}

void CreateHintWord(hangmanGame& activeGame)
//Description:  creates the array of *
{
	//get the length of the word 
	activeGame.wordLength = activeGame.solution.length();
	//let the user know how many letters are in the word
	cout << "There are " << activeGame.solution.length() << " letters in the word.\n";
	//use a loop to create the array of *
	
	for (int i = 0; i < activeGame.wordLength; i++)
	{
		activeGame.hintWord[i] = '*';
	}
	
	//add the null ('\0') character 
	activeGame.hintWord[activeGame.wordLength] = '\0';
	//cout << endl << activeGame.hintWord;
}

void PlayHangman(const string& name, hangmanGame& activeGame)
//Description:  Play one round of the hangman game
{
	cout << "Guess this word: " << endl << activeGame.hintWord << endl;
	//LOOP FOR THE ROUND OF THE GAME
	//the number of incorrect guesses is less than numGuesses
	//and win is false
	while (activeGame.incorrectCount < numGuesses && activeGame.win == false)
	{
		GetLetterGuess(activeGame);
		//UpdateLetterArray - add the letter to the array of guessed letters
		if (InterpretLetterGuess(activeGame) == true)
		{
			//the user guessed a correct letter
			//the user can now guess the word (if they want)
			cout << "\nThe letter was in the word\n";
			CorrectGuess(activeGame, name);
		}
		else
		{
			//the user did not guess a correct letter
			cout << "\nThat letter is incorrect.\n";
			activeGame.incorrectCount++;
		}
		DrawHangman(activeGame);
	}

	//WonOrLostDisplay - lets the user know if they won or lost
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

}

void GetLetterGuess(hangmanGame& activeGame)
//Description:  Displays hint array and letters guessed asks and gets a current letter guess from 
//the user and adds it to the letters guessed array
{
	//display the hint array
	cout << "\n----------------------------------------------------\n";
	cout << "Guess this word: " << endl << activeGame.hintWord << endl;
	//display the letters that have been guessed so far
	cout << "\n----------------------------------------------------\n";
	cout << "Letters guessed: " << endl << activeGame.hintWord << endl;
	//ask and get a letter guess from the user
	cout << "\nEnter a letter: ";
	cin >> activeGame.currentLetter;
	//Add the letter guessed to the letters array
	activeGame.lettersGuessed[activeGame.letterCount] = activeGame.currentLetter;
	//update the letterCount
	activeGame.letterCount++;
	//add the '\0' character
	activeGame.lettersGuessed[activeGame.letterCount] = '\0';
}

bool InterpretLetterGuess(hangmanGame& activeGame)
//Description:  Check if the letter guessed is in the solution and if it is, replace all * with that 
//letter in the hintWord and return true, otherwise return false
{
	bool rv = false;
	for (int i = 0; i < activeGame.wordLength; i++)
	{
		if (activeGame.currentLetter == activeGame.solution[i])
		{
			rv = true;
			activeGame.hintWord[i] = activeGame.currentLetter;
		}
	}
	//use a loop to search the solution word
		//if the letter is found
			//replace the letters in the starword and 
			//set the rv to true
	return rv;
}

void CorrectGuess(hangmanGame& activeGame, string name)
//Description:  checks for the final correct letter and if it is not the final correct letter
//ask and get a word guess from the user if the user wants to guess the word 
{
	char guess = 'y';
	cout << "\n-----------------------------------------";
	//display the starword
	cout << endl << activeGame.hintWord << endl;
	if (GameOver(activeGame)) //the correct letter completed the starword	
	{
		activeGame.win = true;//they won the round by entering all the letters
	}
	else //the user entered a correct letter but it was not the final correct letter
	{
		//ask and get a response (y or n) if they want to guess the word
		if (guess == 'y')
		{
			//prompt for the word 
			cout << "Enter your guess: ";
			//get the word from the user
			cin >> activeGame.userGuess;
			//see if the game is over 
			if (GameOver(activeGame))
			{
				activeGame.win = true;
			}
		}
	}

}

bool GameOver(const hangmanGame& activeGame)
//Description:  This function will return true if the hintWord matches the solution, you can use ==  
//or if the userGuess matches the solution, you can use ==
{
	return activeGame.solution == activeGame.hintWord || activeGame.userGuess == activeGame.solution;
}

void WonOrLostDisplay(const hangmanGame& activeGame, string name)
//Description: Lets the user know if they won or lost the round
{
	cout << "\n-----------------------------------------";
	cout << "\n-----------------------------------------";
	//if (activeGame.win)
	{
		//tell the user they won that round
	}
	//else
	{
		//tell the user they did not win that round
		//display the solution word
	}

}

void DrawHangman(hangmanGame& activeGame)
//Description:  Draw or describe the hangman drawing
{
	cout << "\n------------------------------------------------------";
	cout << "\nO-|--<  O-|--<  O-|--<  O-|--<  O-|--<  O-|--<  O-|--<";
	cout << "\n------------------------------------------------------";
	if (activeGame.incorrectCount == 0)
	{

		cout << "\nYou have no incorrect guesses yet! O-|--<";
	}
	else if (activeGame.incorrectCount == 1)
	{

		cout << "\nHEAD\n - 1 of 6 incorrect guesses!";
	}
	else if (activeGame.incorrectCount == 2)
	{

		cout << "\nHEAD\nBODY\n - 2 of 6 incorrect guesses!";
	}
	else if (activeGame.incorrectCount == 3)
	{

		cout << "\nHEAD\nBODY\nARM1\n - 3 of 6 incorrect guesses!";
	}
	else if (activeGame.incorrectCount == 4)
	{

		cout << "\nHEAD\n\nBODY\nARM1\nARM2\n - 4 of 6 incorrect guesses!";
	}
	else if (activeGame.incorrectCount == 5)
	{

		cout << "\nHEAD\n\nBODY\nARM1\nARM2\nLEG1\n - 5 of 6 incorrect guesses!";
	}
	else if (activeGame.incorrectCount == 6)
	{

		cout << "\nHEAD\n\nBODY\nARM1\nARM2\nLEG1\nLEG2\n - 6 of 6 incorrect guesses! Game Over!";
	}
}
