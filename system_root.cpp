// System of linear equations
#include <iostream>
#include <stdlib.h>
using namespace std;
//Anıl Taşkıran
int rows,colums;
void ekrana(float ** identity);
void show_root(float ** identity);
void delete_point(float ** deleting);
void elimination(float ** array,int i, int j);
void array_input(float ** array);
void elimination_order(float ** array);

int main ()
{
  float ** array;
  string in;
do{
  cout << "---------------" <<
  "Welcome to The System of linear"<<
   " Equations Solver---------------";
   cout << endl << "It can work with with all matrice."<<endl;
   cout << " If you want to solve 6x7" <<
    " matrice please add times by time."<<endl;
  cout << "Please enter row number: ";
    cin >> rows;
  cout << "Please enter colums number: ";
    cin >> colums;

    array= new float*[rows]; //dynamic array
      for (int g=0; g<colums; g++){
         array[g] = new float[colums];
      }


    array_input(array);
    cout << "You entered this array ";
    ekrana(array);

    elimination_order(array);
    show_root(array);


   delete_point(array); //you have to delete dynamic array end of the program
  cout << "for quit please enter 'exit'"<<endl;
}while ((cin >> in) && (in != "exit"));
  return 0;
}

void array_input(float ** array)
{
  for (int i = 0; i <rows; i++)
  { for (int j = 0; j<colums ; j++)
    {
      cout << "please enter a" << i+1 << j+1 <<": ";
      cin >> array[i][j];
    }
  }
}


void elimination_order(float ** array)
{
  for (int t = 0; t < rows; t++)
  { 
    elimination(array,t,t);
      for (int y = 0; y < rows; y++)
      {
        if (t!=y)
        {
          elimination(array,y,t);
        }
      }
  }
}
  
void elimination(float ** array,int i, int j)
{
  float d,q;
  if(i==j)
  {
    d = array[i][i];
    for (int k = 0; k <colums; k++)
    {
      array[i][k] = array[i][k] / d;

    }
  }
  else
  {
    q = -array[i][j] / array[j][j];
    for (int k = 0; k <colums; k++)
    {
      array[i][k] = q*array[j][k] + array[i][k];

    }
  }
}



void ekrana(float ** identity)
{

  cout << "Matrix:  "<<endl;
  for (int n=0; n<rows; n++)
  {
    for (int m=0; m< colums; m++)
    {
       cout << identity[n][m]<<" ";
    }
    cout << endl;
  }
}
void show_root(float ** identity)
{

  cout << "Matrix:  "<<endl;
  for (int n=0; n<rows; n++)
  {
       cout <<"x"<<n<<": " << identity[n][colums-1]<<endl;
  
  }
}


void delete_point(float ** deleting)
{
   for (int n=0; n<colums; n++)
   {
     delete [] deleting[n];
   }
      
    delete[] deleting;
}