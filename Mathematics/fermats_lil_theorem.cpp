#include<iostream>
using namespace std;
#include<cstring>
int mod=1000000;
int stringToInteger(string n,int mod)
{
    int ans=0;
    for(int i=0;i<n.size();i++)
    {
        ans=(ans*10)%mod+n[i]-'0';
        ans=ans%mod;
    }
    return ans;
}
int power(int x,int y,int m)
{
    if(y==1)
    {
        return x;
    }
    if(y==0)
    {
        return 1;
    }

    int sa=power(x,y/2,m)%m;
    int ans=(sa*sa)%m;
    if(y&1)
    {
        ans=(x*ans)%m;
    }
    return ans;
}
int main()
{
    long long t;
    cin>>t;
    string a,b;
    while(t--)
    {
         cin>>a>>b;
         int x=stringToInteger(a,mod);
         int y=stringToInteger(b,mod-1);
         cout<<power(x,y,mod);
    }




}
