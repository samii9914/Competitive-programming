#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void sort(int *arr,int n)
{
    int count[256];
    for(int i=0;i<256;i++)
    {
        count[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        count[arr[i]]=arr[i];
    }
    for(int i=1;i<256;i++)
    {
        count[i]+=count[i-1];
    }
    int ans[n];
    for(int i=n-1;i>=0;i--)
    {
        ans[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }

    for(int i=0;i<n;i++)
    {
        arr[i]=ans[i];
    }
}
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
    sort(arr,n);

    int l=0;
    int r=n-1;
    int diff=INT_MAX;
    int rleft=0;
    int rright=0;
    while(l<r)
    {
        if(arr[l]+arr[r]-sum<diff)
        {
            diff=arr[l]+arr[r]-sum;
            rleft=l;
            rright=r;
        }
       if(arr[l]+arr[r]>sum)
       {
           r--;
       }
       else{
        l++;
       }
    }

    cout<<arr[rleft]<<" "<<arr[rright];
}
