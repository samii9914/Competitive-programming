#include<iostream>
using namespace std;
int m=1000000;
int main()
{
    int n;
    cin>>n;
    int num[n];
    int rem[n];
    int product=1;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        product*=1;
    }
    for(int i=0;i<n;i++)
    {

        cin>>rem[n];
    }

    int ans=0;
    int pp[n];
    int mi[n];

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if((num[i]*j)%m==1)
            {
                mi[i]=j;
                break;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        pp[i]=(product)/num[i];
        ans=ans+(pp[i]*mi[i]+rem[i])%num[i];
    }
    cout<<ans;
}
