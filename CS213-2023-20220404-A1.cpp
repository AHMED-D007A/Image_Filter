void invert_func()
{
	for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        image[i][j] = 255 - image[i][j];
      }
    }
}
void rotate_func()
{
	unsigned char rotatedImage[SIZE][SIZE];
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
          rotatedImage[i][j] = image[255-j][i];
        }
      }
      break;
    case 180:
      for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++)
        {
          rotatedImage[i][j] = image[255-i][255-j];
        }
      }
      break;
    case 270:
      for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++)
        {
          rotatedImage[i][j] = image[j][255-i];
        }
      }
	  break;
	}
	for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++)
        {
          image[i][j] = rotatedImage[i][j];
        }
      }
}