#include<iostream>
using namespace std;
//complexity o(log(b))
int fmf(int a,int b,int m)
{
    int ans=1;
    while(b>0)
    {
        if(b&1)
        {
            ans=(a*ans)%m;
        }
        ans=(ans*ans)%m;
        b=b>>1;
    }
    return ans;
}

int main()
{
    int a,b,m;
    cin>>a>>b>>m;
    cout<<fmf(a,b,m);
}
