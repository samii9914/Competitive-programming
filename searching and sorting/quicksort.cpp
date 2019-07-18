#include<iostream>
using namespace std;
int partition(int *arr,int s,int e)
{
    int pivot=arr[e];
    int pi=s;
    for(int i=s;i<e;i++)
    {
        if(arr[i]<=pivot)
        {
            int temp=arr[i];
            arr[i]=arr[pi];
            arr[pi]=temp;
            pi++;
        }
    }
    swap(arr[e],arr[pi]);
    return pi;
}
void quicksort(int *arr,int s,int e)
{
    if(s<e)
    {
        int pi=partition(arr,s,e);
        quicksort(arr,s,pi-1);
        quicksort(arr,pi+1,e);
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

    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
