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

    bool flag=true;//<
    for(int i=0;i<=n-2;i++)
    {
        if(flag)
        {
            if(arr[i]>arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
        }
        else
        {
            if(arr[i]<arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
        }
        flag=!flag;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
