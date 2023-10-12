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
          for (int k = 0; k < 2; k++)
            for (int l = 0; l < 2; l++)
              enlargedImage[2*i+k][2*j+l] = image[i][j];
        }
      }
      break;
    case '2':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          for (int k = 0; k < 2; k++)
            for (int l = 0; l < 2; l++)
              enlargedImage[2*i+k][2*j+l] = image[i][j+SIZE/2];
        }
      }
      break;
    case '3':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          for (int k = 0; k < 2; k++)
            for (int l = 0; l < 2; l++)
              enlargedImage[2*i+k][2*j+l] = image[i+SIZE/2][j];
        }
      }
      break;
    case '4':
      for (int i = 0; i < SIZE/2; i++)
      {
        for (int j = 0; j < SIZE/2; j++)
        {
          for (int k = 0; k < 2; k++)
            for (int l = 0; l < 2; l++)
              enlargedImage[2*i+k][2*j+l] = image[i+SIZE/2][j+SIZE/2];
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
void skew_right_func()
{
  unsigned char shrinkedImage[SIZE][2*SIZE];
  unsigned char skewedImage[SIZE][SIZE];
  for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        skewedImage[i][j] = 255;
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
          // average = 0;
          // for (int x = 0; x < int(1/scale); x++)
          //   average += image[i][int(j/scale)+x];
          // shrinkedImage[i][j] = average;
          
          shrinkedImage[i][j] = image[i][int(j/scale)];
        }
      }
  for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < int(SIZE - removed); j++)
        {
          skewedImage[i][j+(int)(removed*((255-i)/255.0f))] = shrinkedImage[i][j];
        }
      }
  for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++)
        {
          image[i][j] = skewedImage[i][j];
        }
      }
}