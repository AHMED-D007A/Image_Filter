// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:				CS213-2023-20220251-20220404-20220044-A1-Bonus.cpp
// Last Modification Date:	9/10/2023
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

unsigned char image[SIZE][SIZE][3];

/* functions declaration */
void loadImage(string file_name);
void saveImage();
void Ahlan();
void show_menu();
bool check_file_name(string file_name);

/* filters 2, 5, 8, b and e */
void invert_func_rgb();
void rotate_func_rgb();
void enlarge_func_rgb();
void shuffle_func_rgb();
void skew_right_func_rgb();

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
			break;
		case '2':
			invert_func_rgb();
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			rotate_func_rgb();
			break;
		case '7':
			break;
		case '8':
			enlarge_func_rgb();
			break;
		case '9':
			break;
		case 'a':
			break;
		case 'b':
			shuffle_func_rgb();
			break;
		case 'c':
			break;
		case 'd':
			break;
		case 'e':
			skew_right_func_rgb();
			break;
		case 'f':
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
	readRGBBMP(file_name.c_str(), image);
}

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

	cout << "Cannot open file: " << file_name <<endl;
	return (1);
}

void invert_func_rgb()
{
	for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
          for (int k = 0; k < 3; k++) {
            image[i][j][k] = 255 - image[i][j][k];
          }
        }
      }
}

void rotate_func_rgb()
{
	unsigned char newImage[SIZE][SIZE][3];
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
          for (int k = 0; k < 3; k++)
          {
            newImage[i][j][k] = image[255-j][i][k];
          }
        }
      }
      break;
    case 180:
      for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++)
        {
          for (int k = 0; k < 3; k++)
          {
            newImage[i][j][k] = image[255-i][255-j][k];
          }
        }
      }
      break;
    case 270:
      for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++)
        {
          for (int k = 0; k < 3; k++)
          {
            newImage[i][j][k] = image[j][255-i][k];
          }
        }
      }
	  break;
	}
	for (int i = 0; i < SIZE; i++)
	{
	  for (int j = 0; j < SIZE; j++)
	  {
		for (int k = 0; k < 3; k++)
		{
		  image[i][j][k] = newImage[i][j][k];
		}
	  }
	}
}

void enlarge_func_rgb()
{
	unsigned char enlargedImage[SIZE][SIZE][3];
	char q;
	cout << "Which quarter to enlarge 1, 2, 3 or 4?\n";
    cin >> q;
    switch (q)
    {
    case '1':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          for (int k = 0; k < 3; k++)
          {
            enlargedImage[2*i][2*j][k] = image[i][j][k];
            enlargedImage[2*i+1][2*j][k] = image[i][j][k];
            enlargedImage[2*i][2*j+1][k] = image[i][j][k];
            enlargedImage[2*i+1][2*j+1][k] = image[i][j][k];
          }
        }
      }
      break;
    case '2':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          for (int k = 0; k < 3; k++)
          {
            enlargedImage[2*i][2*j][k] = image[i][j+SIZE/2][k];
            enlargedImage[2*i+1][2*j][k] = image[i][j+SIZE/2][k];
            enlargedImage[2*i][2*j+1][k] = image[i][j+SIZE/2][k];
            enlargedImage[2*i+1][2*j+1][k] = image[i][j+SIZE/2][k];
          }
        }
      }
      break;
    case '3':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          for (int k = 0; k < 3; k++)
          {
            enlargedImage[2*i][2*j][k] = image[i+SIZE/2][j][k];
            enlargedImage[2*i+1][2*j][k] = image[i+SIZE/2][j][k];
            enlargedImage[2*i][2*j+1][k] = image[i+SIZE/2][j][k];
            enlargedImage[2*i+1][2*j+1][k] = image[i+SIZE/2][j][k];
          }
        }
      }
      break;
    case '4':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          for (int k = 0; k < 3; k++)
          {
            enlargedImage[2*i][2*j][k] = image[i+SIZE/2][j+SIZE/2][k];
            enlargedImage[2*i+1][2*j][k] = image[i+SIZE/2][j+SIZE/2][k];
            enlargedImage[2*i][2*j+1][k] = image[i+SIZE/2][j+SIZE/2][k];
            enlargedImage[2*i+1][2*j+1][k] = image[i+SIZE/2][j+SIZE/2][k];
          }
        }
      }
      break;
    }
	for (int i = 0; i < SIZE; i++)
	{
	  for (int j = 0; j < SIZE; j++)
	  {
		for (int k = 0; k < 3; k++)
		{
		  image[i][j][k] = enlargedImage[i][j][k];
		}
	  }
	}
}

void shuffle_func_rgb()
{
	unsigned char shuffledImage[SIZE][SIZE][3];
	int q1, q2, q3, q4;
	cout << "New order of quarters?\n";
	cin >> q1 >> q2 >> q3 >> q4;
	for (int i = 0; i < SIZE / 2; i++)
	{
	  for (int j = 0; j < SIZE / 2; j++)
	  {
		for (int k = 0; k < 3; k++)
		{
		  shuffledImage[i][j][k] = image[i + ((q1 == 1 || q1 == 2) ? 0 : SIZE / 2)][j + ((q1 == 1 || q1 == 3) ? 0 : SIZE / 2)][k];
		}
	  }
	}
	for (int i = 0; i < SIZE / 2; i++)
	{
	  for (int j = 0; j < SIZE / 2; j++)
	  {
		for (int k = 0; k < 3; k++)
		{
		  shuffledImage[i][j + SIZE / 2][k] = image[i + ((q2 == 1 || q2 == 2) ? 0 : SIZE / 2)][j + ((q2 == 1 || q2 == 3) ? 0 : SIZE / 2)][k];
		}
	  }
	}
	for (int i = 0; i < SIZE / 2; i++)
	{
	  for (int j = 0; j < SIZE / 2; j++)
	  {
		for (int k = 0; k < 3; k++)
		{
		  shuffledImage[i + SIZE / 2][j][k] = image[i + ((q3 == 1 || q3 == 2) ? 0 : SIZE / 2)][j + ((q3 == 1 || q3 == 3) ? 0 : SIZE / 2)][k];
		}
	  }
	}
	for (int i = 0; i < SIZE / 2; i++)
	{
	  for (int j = 0; j < SIZE / 2; j++)
	  {
		for (int k = 0; k < 3; k++)
		{
		  shuffledImage[i + SIZE / 2][j + SIZE / 2][k] = image[i + ((q4 == 1 || q4 == 2) ? 0 : SIZE / 2)][j + ((q4 == 1 || q4 == 3) ? 0 : SIZE / 2)][k];
		}
	  }
	}
	for (int i = 0; i < SIZE; i++)
	{
	  for (int j = 0; j < SIZE; j++)
	  {
		for (int k = 0; k < 3; k++)
		{
		  image[i][j][k] = shuffledImage[i][j][k];
		}
	  }
	}
}

void skew_right_func_rgb()
{
	unsigned char shrinkedRGBImage[SIZE][2 * SIZE][3];
	unsigned char skewedRGBImage[SIZE][SIZE][3];
	for (int i = 0; i < SIZE; i++)
	{
	  for (int j = 0; j < SIZE; j++)
	  {
		for (int k = 0; k < 3; k++)
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
		for (int k = 0; k < 3; k++)
		{
		  // average = 0;
		  // for (int x = 0; x < int(1/scale); x++)
		  //   average += image[i][int(j/scale)+x];
		  // shrinkedImage[i][j] = average/;

		  shrinkedRGBImage[i][j][k] = image[i][int(j / scale)][k];
		}
	  }
	}
	for (int i = 0; i < SIZE; i++)
	{
	  for (int j = 0; j < int(SIZE - removed); j++)
	  {
		for (int k = 0; k < 3; k++)
		{
		  skewedRGBImage[i][j + (int)(removed * ((255 - i) / 255.0f))][k] = shrinkedRGBImage[i][j][k];
		}
	  }
	}
	for (int i = 0; i < SIZE; i++)
	{
	  for (int j = 0; j < SIZE; j++)
	  {
		for (int k = 0; k < 3; k++)
		{
		  image[i][j][k] = skewedRGBImage[i][j][k];
		}
	  }
	}
}