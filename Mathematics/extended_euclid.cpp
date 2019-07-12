#include<iostream>
using namespace std;
int x=0,y=0;
int gcd=0;
void extended_euclid(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
        gcd=a;
        return;
    }

    extended_euclid(b,a%b);
    int cx=y;
    int cy=x-(a/b)*b;

    x=cx;
    y=cy;
    cout<<x<<" "<<y<<endl;
}
int main()
{
    int a,b;
    cin>>a>>b;
    extended_euclid(a,b);
}
