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

    for(int times=1;times<n-1;times++)
    {
        int k=arr[times];
        int j=times-1;
        while(j>=0&&arr[j]>k)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }

       arr[j+1]=k;

    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
