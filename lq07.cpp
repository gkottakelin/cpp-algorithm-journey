#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
  string str1,str2 ;
  cin>>str1 >>str2;
  sort(str1.begin(),str1.end());
  sort(str2.begin(),str2.end());
  int j=str1.size();
  int k=str2.size();
  if(j!=k) {cout<<"NO"; return 0;}
  for(int i = 0 ;i < j ; i ++)
  {
    if(str1[i]!=str2[i])
    {
      cout<<"NO"; return 0;
    }
  }
  cout<<"YES";
  return 0;
}