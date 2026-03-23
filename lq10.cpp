#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
  string s1,s2;
  cin>>s1>>s2;
  sort(s1.begin(),s1.end());
  sort(s2.begin(),s2.end());
  long unsigned int k = s1.size();
  if ( k <s2.size()) k=s2.size();
  for(int i=0; i<(int)k ;i++)
  {
    if(s1[i]!=s2[i])
    {
      if(s1.size()>s2.size())
      {
        cout<<s1[i];
        return 0;
      }
      else 
      {
        cout<<s2[i];
        return 0;
      }
    }
  }
  return 0;
}