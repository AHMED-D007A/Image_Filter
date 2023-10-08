// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				CS213-2023-20220251-20220404-20220044-A1-Part1.cpp
// Last Modification Date:	9/10/2023
// Author1 and ID and Group:	Kareem Yossry 20220251
// Author2 and ID and Group:	Youssef Mohamed Saleh 20220404
// Author3 and ID and Group:	Ahmed Mamdouh Mohamed 20220044
// Teaching Assistant:		N/A
// Purpose: Image Filter processing program for gray scale images.

//==================================================================================================================================//

#include <bits/stdc++.h>
#include "bmplib.cpp"


using namespace std;

//==================================================================================================================================//

unsigned char image[SIZE][SIZE];
#include "CS213-2023-20220044-A1.cpp"
#include "CS213-2023-20220404-A1.cpp"
#include "CS213-2023-20220251-A1.cpp"

/* functions declaration */
void loadImage(string file_name);
void saveImage();
void Ahlan();
void show_menu();
bool check_file_name(string file_name);

//==================================================================================================================================//

/**
 * main - the main block to execute the image_filter proccessing application.
 * Return: 0 on success otherwise 1.
 */
int main(void)
{
	string file_name;
	char selection;

	Ahlan();
	cin >> file_name;
	bool check_FN = check_file_name(file_name + ".bmp");

	if (check_FN)
		return (1);

	loadImage(file_name + ".bmp");

	while (true)
	{
		show_menu();
		cin >> selection;

		switch (selection)
		{
		case '1':
			black_and_white_func();
			break;
		case '2':
			invert_func();
			break;
		case '3':
			merge_func();
			break;
		case '4':
			flip_func();
			break;
		case '5':
			darken_lighten_func();
			break;
		case '6':
			rotate_func();
			break;
		case '7':
			/* code */
			break;
		case '8':
			/* code */
			break;
		case '9':
			/* code */
			break;
		case 'a':
			/* code */
			break;
		case 'b':
			/* code */
			break;
		case 'c':
			/* code */
			break;
		case 'd':
			/* code */
			break;
		case 'e':
			/* code */
			break;
		case 'f':
			/* code */
			break;
		case 's':
			saveImage();
			break;
		case '0':
			return (0);
		default:
			cout << "Make sure you choose an available option.\n";
			break;
		}
	}

	return (0);
}

//==================================================================================================================================//

void loadImage(string file_name)
{
	readGSBMP(file_name.c_str(), image);
}

void saveImage()
{
	char imageFileName[100];

	// Get gray scale image target file name
	cout << "Enter the target image file name: ";
	cin >> imageFileName;

	// Add to it .bmp extension and load image
	strcat(imageFileName, ".bmp");
	writeGSBMP(imageFileName, image);
}

/**
 * Ahlan - is a user welcome prompt.
 */
void Ahlan()
{
	cout << "Ahlan ya user ya habibi \1\n";
	cout << "Please enter file name of the image to process: ";
}

/**
 * show_menu - display a list of choices to choose a filter to apply.
*/
void show_menu()
{
cout << "Please select a filter to apply or 0 to exit:"
	 << "\n1-Black & White Filter"
	 << "\n2-Invert Filter"
	 << "\n3-Merge Filter"
	 << "\n4-Flip Image"
	 << "\n5-Darken and Lighten Image"
	 << "\n6-Rotate Image"
	 << "\n7-Detect Image Edges"
	 << "\n8-Enlarge Image"
	 << "\n9-Shrink Image"
	 << "\na-Mirror 1/2 Image"
	 << "\nb-Shuffle Image"
	 << "\nc-Blur Image"
	 << "\nd-Crop Image"
	 << "\ne-Skew Image Right"
	 << "\nf-Skew Image Up"
	 << "\ns-Save the image to a file"
	 << "\n0-Exit\n";
}

/**
 * check_file_name - is a function to check if the given file name is found or not.
 * @file_name: the name of the file
 * Return: 1 on fail and 0 on success.
 */
bool check_file_name(string file_name)
{
	FILE *file = fopen(file_name.c_str(), "rb");

	if ((file))
	{
		fclose(file);
		return (0);
	}

	cout << "Cannot open file: " << file_name <<endl;
	return (1);
}
