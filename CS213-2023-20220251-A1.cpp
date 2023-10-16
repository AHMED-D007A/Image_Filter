 void flip_func()

{
  cout<<"the type 0f the flip: (1)horizontal or (2)vertical";
  int type;
  cin>> type;
  if(type == 1)
  for (int i= 0; i < SIZE; i++)
    
  for (int j = 0; j< SIZE/2; j++)
    {  int t = image[i][j];
       image[i][j]=image[i][255-j];
       image[i][255-j]= t;
    }

  
  else if(type == 2){
    
  for (int i= 0; i < SIZE/2; i++)
        
  for (int j = 0; j< SIZE; j++)
       {int t = image[i][j];
       image[i][j]=image[255-i][j];
       image[255-i][j]= t;
          

    }

   }

 }  
void black_and_white_func()
{
        if (image[i][j] > 127)
            image[i][j] = 255;
        else
            image[i][j] = 0;
}

 void detect_func(){
      
     for (int i = 0; i < SIZE; i++)
     for (int j = 0; j< SIZE; j++){
     
      if ( abs(image[i][j] - image[i+1][j]) > 35 || abs(image[i][j] - image[i][j+1]) > 35)
     {
      image[i][j] = 0;
     }
    
      else
      { 
        image[i][j] = 255;
       
      }
 
      
    }
   }

    void mirror_func(){
    cout<<"entre the type of miror (l)eft  (r)ight  (u)pper  (d)own :";
      char ch;
      cin>>ch;
    if (ch == 'l')
     for (int i = 0; i < SIZE/2; i++)
     for (int j = 0; j< SIZE; j++){
       image[i][j] = image[i][255-j];
    }


    else if (ch =='r' )

     for (int i = 0; i < SIZE; i++)
     for (int j = 0; j< SIZE/2; j++){
       image[i][255-j] = image[i][j];
    }


    else if (ch == 'u')
     for (int i = 0; i < SIZE/2; i++) 
     for (int j = 0; j< SIZE; j++){
      
       image[i][j] = image[255-i][j];
       }


    else if (ch == 'd'){
  
   
     for (int i = 0; i < SIZE/2; i++)
     for (int j = 0; j< SIZE; j++) {
      
       image[255-i][j] = image[i][j];
   }

  }
  
 } 
 void crop_func() 
{   unsigned char cropimage[SIZE][SIZE];

  for (int i = 0; i < SIZE; i++) 
    for (int j = 0; j< SIZE; j++) 
      cropimage[i][j] = 255; 
      int x,y,l,w;
      cout<<"entre starting position in x,y: ";
      cin>>x>>y;
      cout<<"entre lenghth and width: ";
      cin>>l>>w;
      for (int i = x; i < x+l ; i++)
      {
        for (int j = y; j < y+w; j++)
      {
        cropimage[i][j] = image[i][j];
      }
      }
      for (int i = 0; i < SIZE; i++)
      {
        for (int j = 0; j < SIZE; j++)
      {
           image[i][j] = cropimage[i][j];
      }
        
    }
        
}