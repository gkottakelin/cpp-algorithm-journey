#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
  string str,out;
  cin>>str ;
  int j=str.size();
  out+= str[0];
  out+= '1';
  int k = 0 ;
  
  for(int i=1 ;i<j ;i++)
  {
    if(str[i]==out[k])
    {
      out[k+1]++;
    }
    if(str[i]!=out[k])
    {
      if(out[k+1]=='1') 
      {
        out[k+1]=str[i];
        k++;
        out+= '1';
      }
      else if(out[k+1]>'1') 
      {
        out+=str[i];
        k+=2;
        out+= '1';
      }
    }
  }
  int z=out.size();
  if(out[z-1]=='1') out.pop_back();
  for(int i=0 ;i<j-1 ;i++)
  {
    if(str[i]==str[i+1])
    {
      cout<<out;
      return 0;
    }
  }
  cout<<"NO";
  return 0;
}