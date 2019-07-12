#include<iostream>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    int ans=0;
    int xo=x^y;
    int bits=0;
    while(xo)
    {
        bits++;
        xo>>=1;
    }

    int t=1;
    while(bits--)
    {
        xo=xo+t;
        t=t<<1;
    }
    cout<<xo;
}
