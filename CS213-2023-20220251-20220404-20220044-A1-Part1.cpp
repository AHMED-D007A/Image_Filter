#include <bits/stdc++.h>
#include "bmplib.cpp"

using namespace std;

//==================================================================================================================================//

/* functions declaration */
void Ahlan();
int check_file_name();

//================================================================================================================================//

/**
 * main - the main block to execute the image_filter proccessing application.
 * Return: 0 on success otherwise 1.
 */
int main(void)
{
	string file_name;
	cin >> file_name;

	Ahlan();
	int check_FN = check_file_name(file_name);

	if (!check_FN)
		return (1);

	return (0);
}

/**
 * Ahlan - is a user welcome prompt.
 */
void Ahlan(void)
{
	cout << "Ahlan ya user ya habibi \1\n";
}

/**
 * check_file_name - is a function to check if the given file name is found or not.
 * @file_name: the name of the file
 * Return: 0 on fail and 1 on success.
 */
int check_file_name(string file_name)
{
	cout << "Please enter file name of the image to process:";
	FILE *file;

	if (!(file = fopen(file_name + ".bmp", "rb")))
	{
		return (0);
	}
	else
		return (1);
}
