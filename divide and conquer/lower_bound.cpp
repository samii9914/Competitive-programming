#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int no;
    cin>>no;
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==no)
        {
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>no)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    cout<<ans;
}
