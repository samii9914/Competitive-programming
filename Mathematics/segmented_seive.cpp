#include<iostream>
using namespace std;
#define longlong ll
int arr[1000001];
void seive()
{
    for(int i=0;i<=1000000;i++)
    {
        if(arr[i]==1){
        for(int j=i*i;j*j<=1000000;j+=i)
        {
           arr[j]=0;
        }
        }
    }
}
int segmented_seive(ll a,ll b)
{
    seive();
    bool pp[b-a+1];
    memset(pp,1,sizeof(pp));
    for(ll i=2;i*i<=b;i++)
    {
        for(ll j=a;j<=b;j++)
        {
            if(arr[i])
            {
                if(j==i)
                {
                    continue;
                }
                if(j%i==0)
                {
                    pp[j-a]=0;
                }
            }
        }
    }
        int res=1;
        for(ll i=a;i<=b;i++)
        {
            res+=pp[i-a];
        }
        return res;

}
int main()
{
    cout<<segmented_seive();
}
