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
void enlarge_func()
{
    unsigned char enlargedImage[SIZE][SIZE];
    int q;
    cout << "Which quarter to enlarge 1, 2, 3 or 4?\n";
    cin >> q;
    switch (q)
    {
    case '1':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          enlargedImage[2*i][2*j] = image[i][j];
          enlargedImage[2*i+1][2*j] = image[i][j];
          enlargedImage[2*i][2*j+1] = image[i][j];
          enlargedImage[2*i+1][2*j+1] = image[i][j];
        }
      }
      break;
    case '2':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          enlargedImage[2*i][2*j] = image[i][j+SIZE/2];
          enlargedImage[2*i+1][2*j] = image[i][j+SIZE/2];
          enlargedImage[2*i][2*j+1] = image[i][j+SIZE/2];
          enlargedImage[2*i+1][2*j+1] = image[i][j+SIZE/2];
        }
      }
      break;
    case '3':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          enlargedImage[2*i][2*j] = image[i+SIZE/2][j];
          enlargedImage[2*i+1][2*j] = image[i+SIZE/2][j];
          enlargedImage[2*i][2*j+1] = image[i+SIZE/2][j];
          enlargedImage[2*i+1][2*j+1] = image[i+SIZE/2][j];
        }
      }
      break;
    case '4':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          enlargedImage[2*i][2*j] = image[i+SIZE/2][j+SIZE/2];
          enlargedImage[2*i+1][2*j] = image[i+SIZE/2][j+SIZE/2];
          enlargedImage[2*i][2*j+1] = image[i+SIZE/2][j+SIZE/2];
          enlargedImage[2*i+1][2*j+1] = image[i+SIZE/2][j+SIZE/2];
        }
      }
      break;
    }
    for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++)
        {
          image[i][j] = enlargedImage[i][j];
        }
      }
}
void shuffle_func()
{
    unsigned char shuffledImage[SIZE][SIZE];
    int q1, q2, q3, q4;
    cout << "New order of quarters?\n";
    cin >> q1 >> q2 >> q3 >> q4;
    for (int i = 0; i < SIZE/2; i++)
    {
      for (int j = 0; j < SIZE/2; j++)
      {
        shuffledImage[i][j] = image[i + ((q1 == 1 || q1 == 2) ? 0 : SIZE/2)][j + ((q1 == 1 || q1 == 3) ? 0 : SIZE/2)];
      }
    }
    for (int i = 0; i < SIZE/2; i++)
    {
      for (int j = 0; j < SIZE/2; j++)
      {
        shuffledImage[i][j + SIZE/2] = image[i + ((q2 == 1 || q2 == 2) ? 0 : SIZE/2)][j + ((q2 == 1 || q2 == 3) ? 0 : SIZE/2)];
      }
    }
    for (int i = 0; i < SIZE/2; i++)
    {
      for (int j = 0; j < SIZE/2; j++)
      {
        shuffledImage[i + SIZE/2][j] = image[i + ((q3 == 1 || q3 == 2) ? 0 : SIZE/2)][j + ((q3 == 1|| q3 == 3) ? 0 : SIZE/2)];
      }
    }
    for (int i = 0; i < SIZE/2; i++)
    {
      for (int j = 0; j < SIZE/2; j++)
      {
        shuffledImage[i + SIZE/2][j + SIZE/2] = image[i + ((q4 == 1 || q4 == 2) ? 0 : SIZE/2)][j + ((q4 == 1 || q4 == 3) ? 0 : SIZE/2)];
      }
    }
    for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++)
        {
          image[i][j] = shuffledImage[i][j];
        }
      }
}