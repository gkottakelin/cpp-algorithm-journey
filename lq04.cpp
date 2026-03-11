#include <iostream>
using namespace std;
int main()
{
  int s=2025 ;
  int length=2025 , kuan=1,zhouchang=0;
  zhouchang = 2*(length+kuan);
  for( ; length>1022 ; length--)
  {
    if(s%length == 0)
    {
      kuan = s/length;
      if(zhouchang<(2*(length+kuan))) zhouchang =(2*(length+kuan));
    }

  }
  cout<<zhouchang;
  return 0;
}