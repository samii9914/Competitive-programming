#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<3)
    {
        cout<<"-1";
        return 0;
    }
    if(n%2==1)
    {
        cout<<(n*n-1)/2<<" "<<(n*n+1)/2;
    }
    else{
        n=n/2;
        cout<<n*n-1<<" "<<n*n+1;
    }



}
