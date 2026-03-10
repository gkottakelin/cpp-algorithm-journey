#include <iostream>

using namespace std;
int main()
{
  int a=0 , b =0 , min_diff = 0 ;
  cin >> a >> b ;
  if(a>b) 
  {
    int c ;
    c = a ;
    a = b ;
    b = c ;
  }
  min_diff = a+b ;
  for(int i = 1 ; i<= a ; i++ )
  {
    if(abs(4*i-a-b)<min_diff)
    {min_diff = abs(4*i-a-b);}
  }

  cout << min_diff ;
  return 0;
}