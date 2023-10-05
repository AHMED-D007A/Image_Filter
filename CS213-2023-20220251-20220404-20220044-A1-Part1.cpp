#include <bits/stdc++.h>
#include "bmplib.cpp"

using namespace std;

//==================================================================================================================================//

/* functions declaration */
void Ahlan();
int check_file_name(string file_name);

//================================================================================================================================//

/**
 * main - the main block to execute the image_filter proccessing application.
 * Return: 0 on success otherwise 1.
 */
int main(void)
{
	string file_name;

	Ahlan();
	cin >> file_name;
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
	cout << "Please enter file name of the image to process: ";
}

/**
 * check_file_name - is a function to check if the given file name is found or not.
 * @file_name: the name of the file
 * Return: 0 on fail and 1 on success.
 */
int check_file_name(string file_name)
{
	FILE *file;

	char c[file_name.length()];
	for (int i = 0; i < file_name.length(); i++)
	{
		c[i] = file_name[i];
	}

	if (!(file = fopen(strcat(c, ".bmp"), "rb")))
	{
		return (0);
	}
	else
		return (1);
}
