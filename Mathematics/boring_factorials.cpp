#include<iostream>
using namespace std;
//p is a prime number and n is close to p
int fme(int a,int b,int m)
{
    int ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;

    }
    return ans;
}
int solve(int n,int p)
{
    int ans=-1;
    for(int i=n+1;i<=p-1;i++)
    {
        ans=ans*fme(i,p-2,p);
        ans=ans%p;
    }
    return ans+p;
}
int main()
{
    long long t,n,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        if(n>=p)
        {
            cout<<0;
        }
        else{
            cout<<solve(n,p)<<endl;
        }
    }
}
