#include<iostream>
using namespace std;
int addone(int num)
{
    int mask=1;
    while(num&mask!=0)
    {
        num=num^mask;
        mask=mask<<1;
    }
    num=num^mask;
    return num;
}

int main()
{
  int n;
  cin>>n;
  cout<<addone(n);
}
