// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				CS213-2023-S4-20220251-20220404-20220044-A1-Bonus.cpp
// Last Modification Date:	16/10/2023
// Author1 and ID and Group:	Kareem Yossry 20220251
// Author2 and ID and Group:	Youssef Mohamed Saleh 20220404
// Author3 and ID and Group:	Ahmed Mamdouh Mohamed 20220044
// Teaching Assistant:		N/A
// Purpose: Image Filter processing program for RGB images.

//==================================================================================================================================//

#include <bits/stdc++.h>
#include "bmplib.cpp"

using namespace std;

//==================================================================================================================================//

unsigned char image[SIZE][SIZE][RGB];

/* functions declaration */
void loadImage(string file_name);
void saveImage();
void Ahlan();
void show_menu();
bool check_file_name(string file_name);

/* filters 1, 4, 7, a and d */
void black_and_white_func_rgb();
void flip_func_rgb();
void detect_func_rgb();
void mirror_func_rgb();
void crop_func_rgb();

/* filters 2, 5, 8, b and e */
void invert_func_rgb();
void rotate_func_rgb();
void enlarge_func_rgb();
void shuffle_func_rgb();
void skew_right_func_rgb();

/* filters 3, 6, 9, c and f*/
void merge_func_rgb();
void darken_lighten_func_rgb();
void shrink_func_rgb();
void blur_func_rgb();
void skew_up_func_rgb();

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
			black_and_white_func_rgb();
			break;
		case '2':
			invert_func_rgb();
			break;
		case '3':
			merge_func_rgb();
			break;
		case '4':
			flip_func_rgb();
			break;
		case '5':
			darken_lighten_func_rgb();
			break;
		case '6':
			rotate_func_rgb();
			break;
		case '7':
			detect_func_rgb();
			break;
		case '8':
			enlarge_func_rgb();
			break;
		case '9':
			shrink_func_rgb();
			break;
		case 'a':
			mirror_func_rgb();
			break;
		case 'b':
			shuffle_func_rgb();
			break;
		case 'c':
			blur_func_rgb();
			break;
		case 'd':
			crop_func_rgb();
			break;
		case 'e':
			skew_right_func_rgb();
			break;
		case 'f':
			skew_up_func_rgb();
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
	readRGBBMP(file_name.c_str(), image);
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
	writeRGBBMP(imageFileName, image);
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

void black_and_white_func_rgb()
{
	int avg;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			avg = 0;
			for (int k = 0; k < RGB; k++)
			{
				avg += image[i][j][k];
			}
			avg /= 3;
			for (int k = 0; k < RGB; k++)
			{
				image[i][j][k] = avg;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				if (image[i][j][k] > 127)
					image[i][j][k] = 255;
				else
					image[i][j][k] = 0;
			}
		}
	}
}

void invert_func_rgb()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				image[i][j][k] = 255 - image[i][j][k];
			}
		}
	}
}

void merge_func_rgb()
{
	string file_name;
	unsigned char image_2[SIZE][SIZE][RGB];

	cout << "Please enter name of image file to merge with: ";
	cin >> file_name;
	file_name += ".bmp";

	readRGBBMP(file_name.c_str(), image_2);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int l = 0; l < RGB; l++)
				image[i][j][l] = (image[i][j][l] + image_2[i][j][l]) / 2;
		}
	}
}
void flip_func_rgb()
{
	cout << "Flip (h)orizontally or (v)ertically?\n";
	char type;
	cin >> type;
	if (type == 'h')
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE / 2; j++)
				for (int k = 0; k < RGB; k++)
				{
					int t = image[i][j][k];
					image[i][j][k] = image[i][255 - j][k];
					image[i][255 - j][k] = t;
				}
	else if (type == 'v')
	{
		for (int i = 0; i < SIZE / 2; i++)
			for (int j = 0; j < SIZE; j++)
				for (int k = 0; k < RGB; k++)
				{
					int t = image[i][j][k];
					image[i][j][k] = image[255 - i][j][k];
					image[255 - i][j][k] = t;
				}
	}
}

void rotate_func_rgb()
{
	unsigned char newImage[SIZE][SIZE][RGB];
	int r;
	cout << "Rotate (90), (180) or (270) degrees?\n";
	cin >> r;
	switch (r)
	{
	case 90:
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				for (int k = 0; k < RGB; k++)
				{
					newImage[i][j][k] = image[255 - j][i][k];
				}
			}
		}
		break;
	case 180:
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				for (int k = 0; k < RGB; k++)
				{
					newImage[i][j][k] = image[255 - i][255 - j][k];
				}
			}
		}
		break;
	case 270:
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				for (int k = 0; k < RGB; k++)
				{
					newImage[i][j][k] = image[j][255 - i][k];
				}
			}
		}
		break;
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				image[i][j][k] = newImage[i][j][k];
			}
		}
	}
}

void darken_lighten_func_rgb()
{
	char chara;

	cout << "Do you want to (d)arken or (l)ighten?\n";
	cin >> chara;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int l = 0; l < RGB; l++)
			{
				if (chara == 'l')
				{
					if (image[i][j][l] + (image[i][j][l] / 2) > 255)
						image[i][j][l] = 255;
					else
						image[i][j][l] = image[i][j][l] + (image[i][j][l] / 2);
				}
				else if (chara == 'd')
					image[i][j][l] = image[i][j][l] - (image[i][j][l] / 2);
			}
		}
	}
}

void detect_func_rgb()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
		{
			bool color_check = false;
			for (int k = 0; k < RGB; k++)
			{
				if (abs(image[i][j][k] - image[i + 1][j][k]) > 35 || abs(image[i][j][k] - image[i][j + 1][k]) > 35)
					color_check = true;
			}
			for (int k = 0; k < RGB; k++)
			{
				if (!color_check) 
				{
					image[i][j][k] = 255;
				}
			}
		}
}

void enlarge_func_rgb()
{
	unsigned char enlargedImage[SIZE][SIZE][RGB];
	char q;
	cout << "Which quarter to enlarge 1, 2, 3 or 4?\n";
	cin >> q;
	switch (q)
	{
	case '1':
		for (int i = 0; i < SIZE / 2; i++)
		{
			for (int j = 0; j < SIZE / 2; j++)
			{
				for (int k = 0; k < RGB; k++)
				{
					enlargedImage[2 * i][2 * j][k] = image[i][j][k];
					enlargedImage[2 * i + 1][2 * j][k] = image[i][j][k];
					enlargedImage[2 * i][2 * j + 1][k] = image[i][j][k];
					enlargedImage[2 * i + 1][2 * j + 1][k] = image[i][j][k];
				}
			}
		}
		break;
	case '2':
		for (int i = 0; i < SIZE / 2; i++)
		{
			for (int j = 0; j < SIZE / 2; j++)
			{
				for (int k = 0; k < RGB; k++)
				{
					enlargedImage[2 * i][2 * j][k] = image[i][j + SIZE / 2][k];
					enlargedImage[2 * i + 1][2 * j][k] = image[i][j + SIZE / 2][k];
					enlargedImage[2 * i][2 * j + 1][k] = image[i][j + SIZE / 2][k];
					enlargedImage[2 * i + 1][2 * j + 1][k] = image[i][j + SIZE / 2][k];
				}
			}
		}
		break;
	case '3':
		for (int i = 0; i < SIZE / 2; i++)
		{
			for (int j = 0; j < SIZE / 2; j++)
			{
				for (int k = 0; k < RGB; k++)
				{
					enlargedImage[2 * i][2 * j][k] = image[i + SIZE / 2][j][k];
					enlargedImage[2 * i + 1][2 * j][k] = image[i + SIZE / 2][j][k];
					enlargedImage[2 * i][2 * j + 1][k] = image[i + SIZE / 2][j][k];
					enlargedImage[2 * i + 1][2 * j + 1][k] = image[i + SIZE / 2][j][k];
				}
			}
		}
		break;
	case '4':
		for (int i = 0; i < SIZE / 2; i++)
		{
			for (int j = 0; j < SIZE / 2; j++)
			{
				for (int k = 0; k < RGB; k++)
				{
					enlargedImage[2 * i][2 * j][k] = image[i + SIZE / 2][j + SIZE / 2][k];
					enlargedImage[2 * i + 1][2 * j][k] = image[i + SIZE / 2][j + SIZE / 2][k];
					enlargedImage[2 * i][2 * j + 1][k] = image[i + SIZE / 2][j + SIZE / 2][k];
					enlargedImage[2 * i + 1][2 * j + 1][k] = image[i + SIZE / 2][j + SIZE / 2][k];
				}
			}
		}
		break;
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				image[i][j][k] = enlargedImage[i][j][k];
			}
		}
	}
}

void shrink_func_rgb()
{
	cout << "Shrink to (1/2), (1/3) or (1/4)?\n";
	string ss;
	cin >> ss;
	unsigned char new_image[SIZE][SIZE][RGB];

	if (ss == "1/2")
	{
		for (int y = 0; y < SIZE / 2; y++)
		{
			for (int x = 0; x < SIZE / 2; x++)
			{
				int origin_X = x * 2;
				int origin_Y = y * 2;
				for (int z = 0; z < RGB; z++)
				{
					int average = 0;
					for (int i = 0; i < 2; i++)
					{
						for (int j = 0; j < 2; j++)
						{
							average += image[origin_Y + i][origin_X + j][z];
						}
					}
					average = average / 4;
					new_image[y][x][z] = average;
				}
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				for (int l = 0; l < RGB; l++)
				{
					if (i >= SIZE / 2 || j >= SIZE / 2)
						image[i][j][l] = 255;
					else
						image[i][j][l] = new_image[i][j][l];
				}
			}
		}
	}
	if (ss == "1/3")
	{
		for (int y = 0; y < SIZE / 3; y++)
		{
			for (int x = 0; x < SIZE / 3; x++)
			{
				int origin_X = x * 3;
				int origin_Y = y * 3;
				for (int z = 0; z < RGB; z++)
				{
					int average = 0;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							average += image[origin_Y + i][origin_X + j][z];
						}
					}
					average = average / 9;
					new_image[y][x][z] = average;
				}
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				for (int l = 0; l < RGB; l++)
				{
					if (i >= SIZE / 3 || j >= SIZE / 3)
						image[i][j][l] = 255;
					else
						image[i][j][l] = new_image[i][j][l];
				}
			}
		}
	}
	if (ss == "1/4")
	{
		for (int x = 0; x < SIZE / 4; x++)
		{
			for (int y = 0; y < SIZE / 4; y++)
			{
				int origin_X = x * 4;
				int origin_Y = y * 4;
				for (int z = 0; z < RGB; z++)
				{
					int average = 0;
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							average += image[origin_Y + i][origin_X + j][z];
						}
					}
					average = average / 16;
					new_image[y][x][z] = average;
				}
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				for (int l = 0; l < RGB; l++)
				{
					if (i >= SIZE / 4 || j >= SIZE / 4)
						image[i][j][l] = 255;
					else
						image[i][j][l] = new_image[i][j][l];
				}
			}
		}
	}
}

void mirror_func_rgb()
{
	cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?\n";
	char ch;
	cin >> ch;
	if (ch == 'l')
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE / 2; j++)
				for (int k = 0; k < RGB; k++)
				{
					image[i][j][k] = image[i][255 - j][k];
				}

	else if (ch == 'r')
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE / 2; j++)
				for (int k = 0; k < RGB; k++)
				{
					image[i][255 - j][k] = image[i][j][k];
				}

	else if (ch == 'u')
		for (int i = 0; i < SIZE / 2; i++)
			for (int j = 0; j < SIZE; j++)
				for (int k = 0; k < RGB; k++)
				{
					image[i][j][k] = image[255 - i][j][k];
				}

	else if (ch == 'd')
		for (int i = 0; i < SIZE / 2; i++)
			for (int j = 0; j < SIZE; j++)
				for (int k = 0; k < RGB; k++)
				{
					image[255 - i][j][k] = image[i][j][k];
				}
}

void shuffle_func_rgb()
{
	unsigned char shuffledImage[SIZE][SIZE][RGB];
	int q1, q2, q3, q4;
	cout << "New order of quarters?\n";
	cin >> q1 >> q2 >> q3 >> q4;
	for (int i = 0; i < SIZE / 2; i++)
	{
		for (int j = 0; j < SIZE / 2; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				shuffledImage[i][j][k] = image[i + ((q1 == 1 || q1 == 2) ? 0 : SIZE / 2)][j + ((q1 == 1 || q1 == 3) ? 0 : SIZE / 2)][k];
			}
		}
	}
	for (int i = 0; i < SIZE / 2; i++)
	{
		for (int j = 0; j < SIZE / 2; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				shuffledImage[i][j + SIZE / 2][k] = image[i + ((q2 == 1 || q2 == 2) ? 0 : SIZE / 2)][j + ((q2 == 1 || q2 == 3) ? 0 : SIZE / 2)][k];
			}
		}
	}
	for (int i = 0; i < SIZE / 2; i++)
	{
		for (int j = 0; j < SIZE / 2; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				shuffledImage[i + SIZE / 2][j][k] = image[i + ((q3 == 1 || q3 == 2) ? 0 : SIZE / 2)][j + ((q3 == 1 || q3 == 3) ? 0 : SIZE / 2)][k];
			}
		}
	}
	for (int i = 0; i < SIZE / 2; i++)
	{
		for (int j = 0; j < SIZE / 2; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				shuffledImage[i + SIZE / 2][j + SIZE / 2][k] = image[i + ((q4 == 1 || q4 == 2) ? 0 : SIZE / 2)][j + ((q4 == 1 || q4 == 3) ? 0 : SIZE / 2)][k];
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				image[i][j][k] = shuffledImage[i][j][k];
			}
		}
	}
}

void blur_func_rgb()
{
	int average = 0;
	int cownter = 0;
	unsigned char new_image[SIZE][SIZE][RGB];
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int l = 0; l < RGB; l++)
			{
				cownter = 0;
				average = 0;
				for (int x = -2; x <= 2; x++)
				{
					for (int y = -2; y <= 2; y++)
					{
						if (i + x < 256 && i + x > -1 && j + y > -1 && j + y < 256)
						{
							average += image[i + x][j + y][l];
							cownter++;
						}
					}
				}
				new_image[i][j][l] = average / cownter;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int l = 0; l < RGB; l++)
				image[i][j][l] = new_image[i][j][l];
		}
	}
}

void crop_func_rgb()
{
	unsigned char cropimage[SIZE][SIZE][RGB];

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			for (int k = 0; k < RGB; k++)
				cropimage[i][j][k] = 255;

	int x, y, l, w;
	cout << "Please enter x y l w: ";
	cin >> x >> y >> l >> w;
	for (int i = x; i < x + l; i++)
		for (int j = y; j < y + w; j++)
			for (int k = 0; k < RGB; k++)
			{
				cropimage[j][i][k] = image[j][i][k];
			}
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			for (int k = 0; k < RGB; k++)
			{
				image[i][j][k] = cropimage[i][j][k];
			}
}

void skew_right_func_rgb()
{
	unsigned char shrinkedRGBImage[SIZE][2 * SIZE][RGB];
	unsigned char skewedRGBImage[SIZE][SIZE][RGB];
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				skewedRGBImage[i][j][k] = 255;
			}
		}
	}
	float degree;
	cout << "Please enter degree to skew right: ";
	cin >> degree;
	float removed = tan(degree * M_PI / 180) * SIZE;
	float scale = (SIZE - removed) / SIZE;
	int average;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < int(SIZE - removed); j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				shrinkedRGBImage[i][j][k] = image[i][int(j / scale)][k];
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < int(SIZE - removed); j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				skewedRGBImage[i][j + (int)(removed * ((255 - i) / 255.0f))][k] = shrinkedRGBImage[i][j][k];
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < RGB; k++)
			{
				image[i][j][k] = skewedRGBImage[i][j][k];
			}
		}
	}
}

void skew_up_func_rgb()
{
	cout << "Please enter degree to skew Up: ";
	double degree;
	cin >> degree;
	unsigned char new_image[SIZE][SIZE][RGB];

	/*av is for calculating the ratio of the number of the pixel that I am going to give the average of.
	dov is the compelement of the height of the image after being shrinked.*/
	double av = 256 / (256 - (tan(degree / 180 * M_PI) * 256));
	double dov = (tan(degree / 180 * M_PI) * 256);

	for (int y = 0; y < SIZE / av; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			int origin_Y = y * av;
			for (int z = 0; z < RGB; z++)
			{
				double average = 0;
				for (int i = 0; i < (int)av; i++)
				{
					average += image[origin_Y + i][x][z];
				}
				average = average / (int)av;
				new_image[y][x][z] = average;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int l = 0; l < RGB; l++)
			{
				if (i >= SIZE / av)
					image[i][j][l] = 255;
				else
					image[i][j][l] = new_image[i][j][l];
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int l = 0; l < RGB; l++)
				new_image[i][j][l] = 255;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		/* slope and dov determine how every column is being move down */
		double slope = tan(degree / 180 * M_PI) * (double)i;
		for (int j = 0; j < SIZE - (int)dov; j++)
		{
			for (int l = 0; l < RGB; l++)
				new_image[j - (int)slope + (int)dov][i][l] = image[j][i][l];
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int l = 0; l < RGB; l++)
				image[i][j][l] = new_image[i][j][l];
		}
	}
}
