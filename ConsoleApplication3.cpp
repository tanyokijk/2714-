#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

class Game {
private:
	vector <string> wordList;
	string word;

	
public:
	Game()
	{
		ifstream file("слова.txt");
		string слово;
		while (!file.eof())
		{
			file >> слово;
			wordList.push_back(слово);
		}
	}
	void вивід(int спроби)
	{
		switch (спроби)
		{
		case 6:cout << "        $$$$$$$$$$$$$$$\n                      $\n                      $\n                      $\n                      $\n                      $\n                      $\n                      $\n                      $\n                      $\n                      $\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n $                          $\n" << endl; break;
		case 5:cout << "        $$$$$$$$$$$$$$$\n        |             $\n        |             $\n        |             $\n        |             $\n                      $\n                      $\n                      $\n                      $\n                      $\n                      $\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n $                          $\n" << endl; break;
		case 4: cout << "        $$$$$$$$$$$$$$$\n        |             $\n        |             $\n        |             $\n        |             $\n        O             $\n                      $\n                      $\n                      $\n                      $\n                      $\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n $                          $\n" << endl; break; \
		case 3: cout << "        $$$$$$$$$$$$$$$\n        |             $\n        |             $\n        |             $\n        |             $\n        O             $\n      /   \\          $\n                      $\n                      $\n                      $\n                      $\n                      $\n                      $\n                      $\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$                          $\n" << endl; break;
		case 2: cout << "        $$$$$$$$$$$$$$$\n        |             $\n        |             $\n        |             $\n        |             $\n        O             $\n      / | \\          $\n        |             $\n                      $\n                      $\n                      $\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n $                          $\n" << endl; break;
		case 1: cout << "        $$$$$$$$$$$$$$$\n        |             $\n        |             $\n        |             $\n        |             $\n        O             $\n      / | \\          $\n        |             $\n       / \\           $\n                      $\n                      $\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$\n $                          $\n" << endl; break;
		}
	}
	bool game(int рівень)
	{
		if (рівень == 1)
			word = wordList[rand() % 33];
		if (рівень == 2)
			word = wordList[rand() % 33 + 33];
		if (рівень == 3)
			word = wordList[rand() % 33 + 66];

		int wordLength = word.length();
		
		string dispWord(wordLength, '_');

		int found = 0;
		char guess = ' ';
		string guessed="";
		int tries = 6;
		int flagFound = 0;

		while (tries >= 0)
		{
			system("cls");

			for (int i = 0; i < wordLength; i++)
				cout << " " << dispWord[i] << " ";
			cout << endl << endl << endl;

			cout << "Спроби: " << tries << " / " << 6 << endl;
			cout << "Літери: " << guessed<<endl;
			вивід(tries);

			if (found == wordLength) 
			{
				cout << endl;
				cout << "Ви виграли :)" << endl;
				cout << "Бажаєте зіграти ще раз? " << endl;
				cout << "1- Так" << endl;
				cout << "2- Ні" << endl;
				cout << "Будь-який інший символ призведе до вибору <Ні>" << endl;
				int вибір;
				cin>> вибір;
				if (вибір == 1)
					return true;
				else return false;
				break;
			}

			if (tries == 0) break;
			try
			{
				cout << "Виберіть букву:";
				guess = _getche();
				if (guess <= 'a' && guess >= 'z')
				{
					throw 1;
				}
				else if (guessed.find(guess) < 0)
				{
					throw 2;
				}
				else
				{
					throw 3;
				}
			}
			catch (int ex)
			{
				if (ex == 2)
				{
					cout << "Ви ввели некоректний символ.Спробуйте ще раз!" << endl;
				}
				else if (ex == 1)
				{
					cout << "Ви раніше вже вводити такий символ. Спробуйте ще раз!" << endl;
				}
				else if (ex == 3)
				{
					guessed = guessed + " " + guess;

					if (dispWord.find(guess) != string::npos) tries++;

					flagFound = 0;
					for (int i = 0; i < wordLength; i++)
					{
						if (word[i] == guess && dispWord[i] == '_')
						{
							dispWord[i] = guess;
							found++;
							flagFound = 1;
						}
					}

					if (!flagFound)
						tries--;

				}
			}
		}
		if (found != wordLength)
		{
			cout << endl;
			cout << "Ви програли :(" << endl;
			cout << "Загадане слово: " << word << endl;
			cout << "Бажаєте зіграти ще раз? " << endl;
			cout << "1- Так"<<endl;
			cout << "2- Ні" << endl;
			cout << "Будь-який інший символ призведе до вибору <Ні>" << endl;
			int вибір;
			cin >> вибір;
			if (вибір == 1)
				return true;
			else return false;
		}
	return false;
	}
	
}tr;

int main() {
	srand(time(0));
	bool game = true;
	Game tr;
	while (game)
	{

		int спроби = 6;
		string буква;
		cout << "Ласкаво просимо в гру <<Шибениця>>!\n" << endl;
		cout << "На відгадування слова вам даєтся 6 спроб!\n";
		cout << "Якщо ви не відгадали слово ви завжди можете почати з початку!\n";
		cout << "Є 3 рівні складності:\n";
		cout << "1) легкий\n";
		cout << "2) середній\n";
		cout << "3) складний\n";
		cout << "0) вихід\n";
		cout << "Зробіть свій вибір:\n";
		int вибір;
		try
		{
			cin >> вибір;
			if (вибір == 1)
			{
				game=tr.game(1);
			}
			else if (вибір == 2)
			{
				game = tr.game(2);
			}
			else if (вибір == 3)
			{
				game = tr.game(3);
			}
			else if (вибір == 0)
			{
				break;
			}
			else
			{
				throw 0;
			}
		}

		catch (int x)
		{
			if (x == 0)
				cout << "Ви ввели неправильний номер!" << endl;
		}


	}


}
