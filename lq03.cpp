#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int main()
{
  long long n , m , k ;
  cin>> n >> m >> k ;
  vector<int> a(n) ;
  for(int i = 0 ; i<n ; i++)
  {  cin>>a[i]; }
  int rember = a[k-1] ;
  vector<int> b(n);
  for(int i = 0 ; i<n ; i++)
  {
    if(i<k-1)   b[i] = a[i] - rember +1 ;
    if(i>=k-1)  b[i] = a[i] - rember ;
  }
  sort(b.begin(),b.end());
  int go_front = 0 ;
  for(int i = 0 ; i<n&&m>=0 ;i++)
  {
    if(b[i] > 0) //切磋
    {
      m -= b[i] ;
      if( m >=0 ) go_front ++ ;
    } 
  }
  int paiming = 1 ;//找小蓝原本的位置
  for(int i = 0 ; i<n;i++)
  {
    if(a[i]>a[k-1]) paiming++;
    if(a[i]==a[k-1]&&i<k-1) paiming++;
  }
  cout<<paiming-go_front;
  return 0;
}