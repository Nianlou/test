#include <iostream>
//#include "header.h"


int getNum(int &a)
{
	std::cin >> a;
	if (!std::cin.good())
		return -1;
	return 1;
}

LINE* erase (LINE *&lines, int m)
{
	int i;
	for (i = 0; i<m; i++)
		delete[] lines[i].val;
	delete[] lines;
	return nullptr;
}
/*
void output(const char *msg, Line *a, int m)
{
	int i, j;
	std::cout << msg << ":\n";
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < a[i].n; ++j)
		std::cout << a[i].a[j] << " ";
		std::cout << std::endl;
	}
}
*/
void output(LINE *a, int str, int clmn)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < clmn; j++)
		{
			if (a[i].val[j] > 0) 
			{
				std::cout << a[i].val[j] << "  ";
			}
		else std::cout << "0  ";
		}
		std::cout << std::endl;
	}
}

LINE* input(int &str, int &clmn)
{
	LINE *lines = nullptr;
	int s, c; //strings & columns

	std::cout << "Enter the amount of strings:  ";
	if (getNum(s) < 0)
	{
		std::cout << "Please, try again\n";
		return nullptr;
	}
	std::cout << "Enter the amount of columns:  ";
	if (getNum(c) < 0)
        {
                std::cout << "Please, try again\n";
                return nullptr;
        }
	try
	{
		lines = new LINE[s];
	}
	catch (std::bad_alloc &ba)
	{
		std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
		return nullptr;
	}

	std::cout << " \n";
	std::cout << "Lets enter some numbers" << std::endl;
	std::cout << "Enter 0 to exit entering\n";


	str = s;
	clmn = c;
	int N = c * s;
	s = c = 0;

	int elem;
	for (int i = 0; i < N; i++)
	{
//		lines[s].val = new int [lines[s].number];
//		do
//		{
			std::cout << "A column: ";
			if (getNum(c) < 0)
        		{
                		std::cout << "Please, try again\n";
                		return nullptr;
			}
			else if ((c == 0) | (c > clmn)) break;

			std::cout << "\nA string: ";
			if (getNum(s) < 0)
	        	{
                		std::cout << "Please, try again\n";
                		return nullptr;
			}
			else if ((s == 0) | (s > str)) break;

			try
			{
				lines = new LINE[s];
			}
			catch (std::bad_alloc &ba)
			{
				std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
			return nullptr;
			}


			std::cout << "\nAn element: ";

			getNum(elem);
			if (elem < 0)
	        	{
        	        	std::cout << "Please, try again\n";
                		return nullptr;
			}
			else if (elem == 0) break;
			else
			{
				lines[s].number += 1;
				std::cout << "number = #" << lines[s].number << std::endl;
				lines[s].val = new int[lines[s].number];
				lines[s].val[c] = elem;
				std::cout << "elem = " << lines[s].val[c] << std::endl;
			}
	}
//	output(lines, str, clmn);
	return lines;
}


