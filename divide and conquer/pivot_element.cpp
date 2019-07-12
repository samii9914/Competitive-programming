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

    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]>arr[mid+1])
        {
           ans=mid;
           break;
        }
        else if(arr[mid-1]>arr[mid])
        {
            ans=mid-1;
            break;
        }
        else
        {
            //right part
            if(arr[mid]>arr[e])
            {
                s=mid;
            }
            else
            {
                e=mid;
            }
            //left part
            if(arr[s]>arr[mid])
            {
                e=mid;
            }
            else
            {
                s=mid;
            }
        }
    }
    cout<<arr[ans];
}
