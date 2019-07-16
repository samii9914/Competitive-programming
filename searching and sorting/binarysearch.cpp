#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int key;
    cin>>key;

    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(arr[mid]==key)
        {
            cout<<"element found at index "<<mid;
            return 0;
        }
        else if(arr[mid]<key)
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }

    cout<<"Element not found"<<endl;
    return 0;
}
