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

void shrink_func()
{
	cout << "Shrink to (1/2), (1/3) or (1/4)?\n";
	string ss;
	cin >> ss;
	unsigned char new_image[SIZE][SIZE];

	if (ss == "1/2")
	{
		for (int y = 0; y < SIZE / 2; y++)
		{
			for (int x = 0; x < SIZE / 2; x++)
			{
				int origin_X = x * 2;
				int origin_Y = y * 2;
				int average = 0;
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						average += image[origin_Y + i][origin_X + j];
					}
				}
				average = average / 4;
				new_image[y][x] = average;
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (i >= SIZE / 2  || j >= SIZE / 2)
					image[i][j] = 255;
				else
					image[i][j] = new_image[i][j];
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
				int average = 0;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						average += image[origin_Y + i][origin_X + j];
					}
				}
				average = average / 9;
				new_image[y][x] = average;
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (i >= SIZE / 3 || j >= SIZE / 3)
					image[i][j] = 255;
				else
					image[i][j] = new_image[i][j];
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
				int average = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						average += image[origin_Y + i][origin_X + j];
					}
				}
				average = average / 16;
				new_image[y][x] = average;
			}
		}
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (i >= SIZE / 4 || j >= SIZE / 4)
					image[i][j] = 255;
				else
					image[i][j] = new_image[i][j];
			}
		}
	}
}
