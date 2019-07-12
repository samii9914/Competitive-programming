#include<iostream>
using namespace std;
int power(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n==1)
    {
        return x;
    }

    int sa=power(x,n/2);
    int ans=sa*sa;
    if(n&1)
    {
        ans=x*ans;
    }
    return ans;
}
int main()
{
    int x,n;
    cin>>x>>n;
    cout<<power(x,n);
}
