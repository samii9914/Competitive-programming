#include<iostream>
using namespace std;
#include<vector>

int* primes()
{
    int prime[1001]={1};
for(int i=2;i<=1000;i++)
    {
        for(int j=2;j*j<i;j++)
        {
            if(i%j==0)
            {
                prime[i]=0;
              break;
            }
        }
    }
}
int factors(int n)
{
    int i=0;
    int *prime=primes();
    int sum=0;
    while(n>0)
    {
        if(n%prime[i]==0)
        {
            n=n/10;
            sum=sum+prime[i];
        }
        else{
            i++;
        }

    }
    return sum;

}
int boston(int n)
{
    int sum=factors(n);
    int ans=0;
    while(n>0)
    {
        ans=ans+(n%10);
        n=n/10;
    }
    if(ans==sum)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<boston(n);
}
