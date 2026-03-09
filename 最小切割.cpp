#include <iostream>
using namespace std;
int main()
{
  int N ;
  cin >> N ;
  char S[N+1] ;
  cin >> S ;
  int count[256]={0} , sum = 0 ;
  for(int i=0 ; i<N ; i++)
  {
    count[S[i]]++;
  }
  for(int i='a' ; i<='z' ; i++)
  {
    sum+=(count[i]%2); 
  }
  if(sum == 0) sum = 1 ;
  //cout << S << endl;
  cout << sum ;
  return 0;
}
