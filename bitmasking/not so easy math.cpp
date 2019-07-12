#include<iostream>
using namespace std;
int main()
{
    int primes[21]={0};
    primes[0]=1;
    primes[1]=1;
    for(int i=2;i<21;i++)
    {
        for(int j=2;j*j<i;j++)
        {
            if(i%j==0)
            {
                break;
            }
            primes[i]=1;
        }
    }
    int count=0;
    int t;
    cin>>t;
    while(t--)
    {
        count=0;
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<20;j++)
            {
                if(primes[j]==1&&i%j==0)
                {
                    count++;
                }
            }
        }
        cout<<count-1<<endl;
    }
}
