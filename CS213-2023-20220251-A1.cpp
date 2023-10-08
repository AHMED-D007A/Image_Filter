void flip_func()
{
	cout << "Flip (h)orizontally or (v)ertically?\n";
	int type;
	cin >> type;
	if (type == 1)
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE / 2; j++)
			{
				int t = image[i][j];
				image[i][j] = image[i][255 - j];
				image[i][255 - j] = t;
			}

	else if (type == 2)
	{
		for (int i = 0; i < SIZE / 2; i++)
			for (int j = 0; j < SIZE; j++)
			{
				int t = image[i][j];
				image[i][j] = image[255 - i][j];
				image[255 - i][j] = t;
			}
	}
}

void black_and_white_func()
{
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
