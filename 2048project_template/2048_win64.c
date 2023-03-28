#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

 
int a[4][4];
int i,j,k;
 
int move_up()
{
 int f=0;//have moved then f=1，no movement is 0
 for(j=0;j<4;j++)
 {
  for(i=1;i<4;i++)
  {
   if(a[i][j]!=0)//find the number not 0
   {
    for(k=0;k<i;k++)
    {
     if(a[k][j]==0)//the first 0 upper
     {
      a[k][j]=a[i][j];
      a[i][j]=0;
      f=1;
      break;
     }
    }
   }
  }
 }
 return f;
}
 
int move_down()
{
 int f=0;
 for(j=0;j<4;j++)
 {
  for(i=2;i>=0;i--)
  {
   if(a[i][j]!=0)
   {
    for(k=3;k>i;k--)
    {
     if(a[k][j]==0)
     {
      a[k][j]=a[i][j];
      a[i][j]=0;
      f=1;
      break;
     }
    }
   }
  }
 }
 return f;
}
 
int move_left()
{
 int f=0;
 for(i=0;i<4;i++)
 {
  for(j=1;j<4;j++)
  {
   if(a[i][j]!=0)
   {
    for(k=0;k<j;k++)
    {
     if(a[i][k]==0)
     {
      a[i][k]=a[i][j];
      a[i][j]=0;
      f=1;
      break;
     }
    }
   }
  }
 }
 return f;
}
 
int move_right()
{
 int f=0;
 for(i=0;i<4;i++)
 {
  for(j=2;j>=0;j--)
  {
   if(a[i][j]!=0)
   {
    for(k=3;k>j;k--)
    {
     if(a[i][k]==0)
     {
      a[i][k]=a[i][j];
      a[i][j]=0;
      f=1;
      break;
     }
    }
   }
  }
 }
 return f;
}
 
 
int up()
{
 int f=0;//have merged，f=1，no :0
 //move
 int f1=move_up();//have moved f1=1
 //merge
 for(j=0;j<4;j++)
 {
  for(i=0;i<3;i++)
  {
   if(a[i][j]==a[i+1][j]&&a[i][j]!=0)
   {
    a[i][j]=2*a[i][j];
    a[i+1][j]=0;
    f=1;
   }
  }
 }
 if(f==1)
  move_up();
 return (f||f1);
}
 
int down()
{
 int f=0;
 //move
 int f1=move_down();
 //merge
 for(j=0;j<4;j++)
 {
  for(i=3;i>0;i--)
  {
   if(a[i][j]==a[i-1][j]&&a[i][j]!=0)
   {
    a[i][j]=2*a[i][j];
    a[i-1][j]=0;
    f=1;
   }
  }
 }
 if(f==1)
  move_down();
 return (f||f1);
}
 
int left()
{
 int f=0;
 //move
 int f1=move_left();
 //merge
 for(i=0;i<4;i++)
 {
  for(j=0;j<3;j++)
  {
   if(a[i][j]==a[i][j+1]&&a[i][j]!=0)
   {
    a[i][j]=2*a[i][j];
    a[i][j+1]=0;
    f=1;
   }
  }
 }
 if(f==1)
  move_left();
 return (f||f1);
}
 
int right()
{
 int f=0;
 //move
 int f1=move_right();
 //merge
 for(i=3;i>=0;i--)
 {
  for(j=3;j>0;j--)
  {
   if(a[i][j]==a[i][j-1]&&a[i][j]!=0)
   {
    a[i][j]=2*a[i][j];
    a[i][j-1]=0;
    f=1;
   }
  }
 }
 if(f==1)
  move_right();
 return (f||f1);
}
 
 
int ran()//random
{
 int z[8]={2,2,2,2,2,2,2,4};//2 is much more possible
 srand(time(NULL));
lb:
 i=rand()%4;
 j=rand()%4;
 if(a[i][j]==0)
  a[i][j]=z[rand()%8];
 else
  goto lb;
}
 
 
int fail()//fail
{
 int count=0;
 for(i=0;i<4;i++)
 {
  for(j=0;j<3;j++)
  {
   if(a[i][j]==a[i][j+1])//net yet fail
   {
    return 0;
   }
  }
 }
 for(i=0;i<3;i++)
 {
  for(j=0;j<4;j++)
  {
   if(a[i][j]==a[i+1][j])//net yet fail
   {
    return 0;
   }
  }
 }
 for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
   if(a[i][j]==0)//count the blank squares
   {
    count++;
   }
  }
 }
 if(count==0)//no blank
 {
  printf("\n You nearly win, unfortunately!\n");
  return 1;
 }
 return 0;
}
 
 
 
int main()
{
 char n;
 ran();
 while(1)
 {
  
  ran();
  
  system("cls");//clear screen
  printf("\n---------------------------------\n");
  for(i=0;i<4;i++)
  {
   printf("|");
   for(j=0;j<4;j++)
   {
    if(a[i][j]==0)
     printf("       |");
    else
     printf("%5d  |",a[i][j]);
   }
   printf("\n---------------------------------\n");
  }
  printf("\n\nw,s,a,d-->up down left right and ESC to end the game \n");
   
lab: 
   n = _getch();
  switch(n)
  {
   case 'w': //up
    if(0==up())
    {
     if(1==fail())
      return -1;
     else
      goto lab;
    }
    break;
   case 's': //down
    if(0==down())
    {
     if(1==fail())
      return -1;
     else
      goto lab;
    }
    break;
   case 'a': //left
    if(0==left())
    {
     if(1==fail())
      return -1;
     else
      goto lab;
    }
    break;
   case 'd': //right
    if(0==right())
    {
     if(1==fail())
      return -1;
     else
      goto lab;
    }
    break;
   case 27: //ESC
    printf("\n Exit Game ！\n");
    return 0;
   default:
    goto lab;
  }
  //win or not
  for(i=0;i<4;i++)
  {
   for(j=0;j<4;j++)
   {
    if(a[i][j]==2048)//2048 win
    {
     printf("\n You win！\n");
     return 1;//end
    } 
   }
  }
 }
 
 return 0;
}