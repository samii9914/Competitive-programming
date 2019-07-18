#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int sum;
    cin>>sum;
    int ans=0;
    for(int i=0;i<n-2;i++)
    {
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
            if(arr[i]+arr[j]+arr[k]>=sum)
            {
                k--;
            }
            else{
                ans+=(k-j);
                j++;
            }
        }
    }

    cout<<ans<<endl;
}
