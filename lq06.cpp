#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
  string a ; 
  cin>>a ;
  sort(a.begin(),a.end());
  int j=a.size() ;
  for(int i =0 ; i<j ; i++)
  {
      if(a[i] == a[i+1]) 
      {
        cout<<"NO" ;
        return 0 ;
      }
  }
  // cout<<a ;
  cout << "YES";
  return 0;
}