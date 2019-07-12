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

    int key;
    cin>>key;
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int  mid=(s+e)/2;
        if(arr[mid]==key)
        {
            ans=mid;
            break;
        }
         if(arr[s]<=arr[mid])
        {
            if(arr[s]<=key&&key<=arr[mid])
            {
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        if(arr[mid]<=arr[e])
        {
            if(arr[mid]<=key&&key<=arr[e])
            {
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    cout<<ans;
}
