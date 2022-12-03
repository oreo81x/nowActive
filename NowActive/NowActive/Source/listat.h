
#ifndef LISTAT_H
#define LISTAT_H

#include <string>
#include <conio.h>
#include "color.h"

// Listat [ Class ]
// To create lists
class Listat
{
public:
	friend class NewListat;

public:
	// constructor
	Listat()
	{}

	// constructor
	// To set values
	Listat(int CURRENT, int MAX, int MIN, int DEF) : current(CURRENT - 1), maxline(MAX - 1), minline(MIN - 1), defline(DEF - 1)
	{}

	// Useless Destructor
	~Listat()
	{}

public:
	// properties()
	// To set values
	void properties(int CURRENT, int MAX, int MIN, int DEF)
	{
		current = (CURRENT - 1),
			maxline = (MAX - 1),
			minline = (MIN - 1),
			defline = (DEF - 1);
	}

	// Current()
	// To change [int] current value
	void Current(int CURRENT)
	{
		current = CURRENT;
	}

	// vertical_Sort()
	// To sort the list vertical as normal lists
	void vertical_Sort(std::string title[], int style = 0)
	{
		// Handle the [int] style less or over value
		if (style < 0)style = 0;
		if (style > 1)style = 1;

#ifdef _WIN32
		system("CLS");
#else
		system("CLEAR");
#endif // _WIN32

		// loop to print all list titles
		for (int counter = 0; counter <= maxline; counter++)
		{
			// if [int] style = 0
			if (style == 0)
			{
				// if loop counter = the selected line value
				if (counter == current)
				{
					std::cout << dye::light_red_on_black("  [ ");
					std::cout << dye::light_yellow_on_black(title[counter]);
					std::cout << dye::light_red_on_black(" ] ");
				}
				else
				{
					std::cout << " " << dye::bright_white_on_black(title[counter]);
				}
			}

			// if [int] style = 1
			if (style == 1)
			{
				// if loop counter = the selcted line value
				if (counter == current)
				{
					std::cout << " " << dye::black_on_bright_white(" ");
					std::cout << dye::black_on_bright_white(title[counter]);
					std::cout << dye::black_on_bright_white(" ");
				}
				else
				{
					std::cout << " " << dye::black_on_grey(" ");
					std::cout << dye::black_on_grey(title[counter]);
					std::cout << dye::black_on_grey(" ");
				}
			}

			std::cout << std::endl;
		}
	}

	// Input()
	// To change list variables values about user input
	void Input(bool vertical)
	{
		char less[2] = { 0,0 };
		char post[2] = { 0,0 };

		if (vertical)
		{
			less[0] = 'w', less[1] = 'W';
			post[0] = 's', post[1] = 'S';
		}
		if (!vertical)
		{
			less[0] = 'a', less[1] = 'A';
			post[0] = 'd', post[1] = 'D';
		}

		input = _getch();

		if (input == less[0] || input == less[1])
		{
			(current <= minline) ? current = maxline : current--;
		}
		if (input == post[0] || input == post[1])
		{
			(current >= maxline) ? current = minline : current++;
		}
		if (input == 'x' || input == 'X' || input == '0')
		{
			current = defline;
		}
	}

public:
	// theChar()
	// Return [char] input value
	char theChar()
	{
		return input;
	}

	// Current()
	// Return [int] current value
	int Current()
	{
		return current;
	}

	// Max()
	// Return [int] max value
	int Max()
	{
		return maxline;
	}

	// Min()
	// Return [int] min value
	int Min()
	{
		return minline;
	}

	// Def()
	// Return [int] def value
	int Def()
	{
		return defline;
	}

private:

protected:
	char input = 0;
	int current = 0;
	int maxline = 0;
	int minline = 0;
	int defline = 0;

};

// ListatPlus [ class ] 
// Inherited from Listat class
class NewListat :public Listat
{
public:
	void listProperties(int CURRENTLIST, int MAXLIST, int MINLIST, int DEFLIST)
	{
		currentlist = (CURRENTLIST - 1), maxlist = (MAXLIST - 1), minlist = (MINLIST - 1), deflist = (DEFLIST - 1);
	}

	// horizontal_Sort()
	void horizontal_Sort(std::string title1[], std::string title2[][99], Listat list[])
	{
		clear();
		// loop to print all objects
		for (int counter = 0; counter <= maxlist; counter++)
		{
			// avoid some array errors
			if (list[counter].defline < 0)list[counter].defline = 0;
			if (list[counter].current < 0)list[counter].current = 0;

			// if the loop counter = [int] currentlist value
			if (counter == currentlist)
			{
				std::cout << "   " << dye::light_yellow_on_black(title1[counter]);
				std::cout << dye::light_red_on_black(" < ");
				std::cout << dye::light_yellow_on_black(title2[counter][list[counter].current]);
				std::cout << dye::light_red_on_black(" > ");
			}
			else
			{
				std::cout << "  " << dye::bright_white_on_black(title1[counter]);
				std::cout << dye::light_red_on_black(" < ");
				std::cout << dye::bright_white_on_black(title2[counter][list[counter].current]);
				std::cout << dye::light_red_on_black(" > ");
			}
			std::cout << std::endl;
		}
	}

	// nastedInput()
	void nasatedInput(Listat* list)
	{
		input = _getch();

		if (input == 'w' || input == 'W')
		{
			(currentlist <= minlist) ? currentlist = maxlist : currentlist--;
		}
		if (input == 's' || input == 'S')
		{
			(currentlist >= maxlist) ? currentlist = minlist : currentlist++;
		}

		if (input == 'a' || input == 'A')
		{
			(list->current <= list->minline) ? list->current = list->maxline : list->current--;
		}
		if (input == 'd' || input == 'D')
		{
			(list->current >= list->maxline) ? list->current = list->minline : list->current++;
		}

		if (input == 'x' || input == 'X' || input == '0')
		{
			currentlist = deflist;
		}
	}

public:
	// theChar()
	// Return [char] input value
	char theChar()
	{
		return input;
	}

	// Currentlist()
	// Return [int] currentlist value
	int Currentlist()
	{
		return currentlist;
	}

	// Maxlist()
	// Return [int] maxlist value
	int Maxlist()
	{
		return maxlist;
	}

	// Minlist()
	// Return [int] minlist value
	int Minlist()
	{
		return minlist;
	}

	// Deflist()
	// Return [int] deflist value
	int Deflist()
	{
		return deflist;
	}

private:
	int currentlist = 0;
	int maxlist = 0;
	int minlist = 0;
	int deflist = 0;

protected:

};

#endif // !LISTAT_h
