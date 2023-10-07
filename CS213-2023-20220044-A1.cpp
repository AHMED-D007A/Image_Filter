#include <bits/stdc++.h>
#include "bmplib.cpp"

void merge_func()
{
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
