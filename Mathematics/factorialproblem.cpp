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
        ans=ans*x;
    }
    return ans;
}
int fact(int n)
{
    int ans=1;
    for(int i=n;i>=1;i--)
    {
        ans=ans*i;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    int n,k;
    int x=1;
    int ans=1;
    while(t--)
    {
        cin>>n>>k;
        long f=fact(n);
        while(1)
        {
            if(f%(power(k,x))==0)
            {
                ans=x;
            }
            else{
                break;
            }
            x++;
        }
         cout<<ans;
    }

}
