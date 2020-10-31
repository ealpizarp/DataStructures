#include <iostream>

using namespace std;

int main()
{
    cout<<"Hola"<<endl;
  int arr[] = {1,1, 2,2,5,8,13,21,34,54};
  int  *p;
  p = &arr[4];
  cout<<*p<<endl;
  cout<<p[2]<<endl;
  p[5]= 55;
  p[-1] = 3;
  p = &arr[1];
  cout<<arr[3]<<endl;
  cout<<p[9]<<endl;


  int **m;
  int r = 15;
  int c = 10;

  m = new int *[r];
  for(int i = 0; i<r; i++){
    m[i] = new int[c];

  }




}
