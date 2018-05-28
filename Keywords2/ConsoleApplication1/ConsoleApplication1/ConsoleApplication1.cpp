// CodeBreaker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
char again;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	do {
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 10;
		const string WORDS[NUM_WORDS][NUM_FIELDS] =
		{
			{ "rain", "it falls from the sky" },
			{ "boat","likes to float" },
			{ "book","old fashioned kindle" },
			{ "simulation","is it real" },
			{ "cheese","its dairy product" },
			{ "guitar", "A stringed instument" },
			{ "lamp","gives you some light" },
			{ "tank","Armoured fighting vehichle" },
			{ "engine","your car has one" },
			{ "towel","you use this to dry off" }
		};


		const int WordNUM = 3;
		//array for the jumbled words
		string GuessWords[WordNUM][NUM_FIELDS] =
		{
			{ "word1", "guess1" },
			{ "word2", "guess2" },
			{ "word3", "guess3" }
		};
		//array for correct words
		string CorrectWords[WordNUM][NUM_FIELDS] =
		{
			{ "word1", "guess1" },
			{ "word2", "guess2" },
			{ "word3", "guess3" }
		};



		for (int i = 0;i < 3;i++) {
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD]; //word to guess
			CorrectWords[i][0] = theWord; //sets the correct word to the array

			string theHint = WORDS[choice][HINT]; //hint for the guess
			CorrectWords[i][1] = theHint; //sets the correct hint in the array

			string jumble = theWord;
			string jumblecheck = jumble;

			int length = jumble.size();
			do
			{
				for (int i = -1; i < (length - 1); ++i)
				{
					int index1 = (rand() % length);
					int index2 = (rand() % length);
					char temp = jumble[index1];
					jumble[index1] = jumble[index2];
					jumble[index2] = temp;


				}

				//have it check to make sure it didnt end up the smae as it started
			} while (jumble == jumblecheck);

			//sets the jumbled word in the array
			GuessWords[i][0] = jumble;
			//cout << GuessWords[i][0] << "\n";
			GuessWords[i][1] = theHint;
			//cout << GuessWords[i][1] <<"\n";
		}


		cout << "Welcome to Code Breaker Training Simualation\n\n";
		cout << "You will be given 3 scrambled words.\n";
		cout << "Unscramble the letters to make the word.\n";
		cout << "Enter 'hint' for a hint.\n";
		cout << "Enter 'quit' to quit the game.\n";

		cout << "The Scambled words are : " << GuessWords[0][0];
		cout << "\n" << GuessWords[1][0];
		cout << "\n" << GuessWords[2][0];

		string guess;


		for (int u = 0; u < 3;++u)
		{
			cout << "\nThe scramble is : " << GuessWords[u][0];
			cout << "\n\nYour guess for word " << (u + 1) << ": ";
			cin >> guess;
			// the correct word is checked each time by the increasing u value to get the diffrent words
			while ((guess != CorrectWords[u][0]) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << CorrectWords[u][1];
				}
				else
				{
					cout << "Sorry thats not it.";
				}
				cout << "\nThe scramble is : " << GuessWords[u][0];
				cout << "\n\nYour guess: ";
				cin >> guess;
			}

			if (guess == CorrectWords[u][0])
			{
				cout << "\nThats correct";

			}

			if (guess == "quit")
			{
				cout << "\nThanks for playing.";
				again = 'n';
				break;
			}
		}
		if (guess != "quit")
		{
			cout << "\nWould you like to run the program again?\n";
			cin >> again;
		}


	} while (again == 'y');
	return 0;
}
