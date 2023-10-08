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

void darken_lighten_func()
{
	char chara;

	cout << "Do you want to (d)arken or (l)ighten?\n";
	cin >> chara;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (chara == 'l')
			{
				if (image[i][j] + (image[i][j] / 2) > 255)
					image[i][j] = 255;
				else
					image[i][j] = image[i][j] + (image[i][j] / 2);
			}
			else if (chara == 'd')
				image[i][j] = image[i][j] - (image[i][j] / 2);
		}
	}
}
