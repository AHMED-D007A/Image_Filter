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

/* functions declaration */
void loadImage(string file_name);
void saveImage();
void Ahlan();
void show_menu();
bool check_file_name(string file_name);

// filter 1 and 4.
void black_and_white_func();
void flip_func();

// filter 2 and 5.
void invert_func();
void rotate_func();
// filter 3 and 6.
void merge_func();
void darken_lighten_func();

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
			cout << "Not Ready Yet!\n";
			break;
		case '8':
			cout << "Not Ready Yet!\n";
			break;
		case '9':
			cout << "Not Ready Yet!\n";
			break;
		case 'a':
			cout << "Not Ready Yet!\n";
			break;
		case 'b':
			cout << "Not Ready Yet!\n";
			break;
		case 'c':
			cout << "Not Ready Yet!\n";
			break;
		case 'd':
			cout << "Not Ready Yet!\n";
			break;
		case 'e':
			cout << "Not Ready Yet!\n";
			break;
		case 'f':
			cout << "Not Ready Yet!\n";
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

/**
 * loadImage - a func that takes the image name that want to be opened.
 * @file_name: the name of the file to be opened.
 */
void loadImage(string file_name)
{
	readGSBMP(file_name.c_str(), image);
}

/**
 * saveImage - save the modifications in a new image file with a given name.
 */
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

	cout << "Cannot open file: " << file_name << endl;
	return (1);
}

//==================================================================================================================================//

/**
 * black_and_white_func - a function that return the given image in black and white only.
 */
void black_and_white_func()
{
	/*if the pixel value is bigger than 127 it makes it 255(white) otherwise makes it 0(black)*/
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (image[i][j] > 127)
				image[i][j] = 255;
			else
				image[i][j] = 0;
		}
	}
}

/**
 * flip_func - a function that return the given image flipped Horizontally or Vertically by your choice.
 */
void flip_func()
{
	cout << "Flip (h)orizontally or (v)ertically?\n";
	char type;
	cin >> type;
	if (type == 'h')
		/*it swaps two pixels in same row which result in horizontal flip*/
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE / 2; j++)
			{
				int t = image[i][j];
				image[i][j] = image[i][255 - j];
				image[i][255 - j] = t;
			}
	else if (type == 'v')
	{
		/*it swaps two pixels in same column which result in vertical flip*/
		for (int i = 0; i < SIZE / 2; i++)
			for (int j = 0; j < SIZE; j++)
			{
				int t = image[i][j];
				image[i][j] = image[255 - i][j];
				image[255 - i][j] = t;
			}
	}
}

/**
 * invert_func - invert all pixels values of the image.
 */
void invert_func()
{
	/* Inverts the pixel by getting the complement of the pixel value */
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			image[i][j] = 255 - image[i][j];
		}
	}
}

/**
 * rotate_func - rotate the given image by 90, 180 and 270 by a given input.
 */
void rotate_func()
{
	unsigned char rotatedImage[SIZE][SIZE];
	int r;
	cout << "Rotate (90), (180) or (270) degrees?\n";
	cin >> r;
	switch (r)
	{
	case 90:
		/*it takes the i-th column from bottom to top and transforms it to the i-th row from left to right.*/
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				rotatedImage[i][j] = image[255 - j][i];
			}
		}
		break;
	case 180:
		/*it takes the n(number of rows) - i-th row from right to left and transforms it to the i-th row from left to right.*/
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				rotatedImage[i][j] = image[255 - i][255 - j];
			}
		}
		break;
	case 270:
		/*it takes n(number of columns) - i-th column from top to bottom and transforms it to the i-th row from left to right.*/
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				rotatedImage[i][j] = image[j][255 - i];
			}
		}
		break;
	}
	/*saves it to the given image.*/
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			image[i][j] = rotatedImage[i][j];
		}
	}
}

/**
 * merge_func - it merges two given images.
 */
void merge_func()
{
	/*it saves the average of the same indexed two pixels of the two given images to the new image.*/
	string file_name;
	unsigned char image_2[SIZE][SIZE];

	cout << "Please enter name of image file to merge with: ";
	cin >> file_name;
	file_name += ".bmp";

	readGSBMP(file_name.c_str(), image_2);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			image[i][j] = (image[i][j] + image_2[i][j]) / 2;
		}
	}
}

/**
 * darken_lighten_func - it changes the level of brightness of the image by darkening or lightening it.
 */
void darken_lighten_func()
{
	char chara;

	cout << "Do you want to (d)arken or (l)ighten?\n";
	cin >> chara;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			/*it multiply every pixel by 1.5*/
			if (chara == 'l')
				if (image[i][j] + (image[i][j] / 2) > 255)
					image[i][j] = 255;
				else
					image[i][j] = image[i][j] + (image[i][j] / 2);
			/*it multiply every pixel by .5*/
			else if (chara == 'd')
				image[i][j] = image[i][j] - (image[i][j] / 2);
		}
	}
}
