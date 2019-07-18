#include<iostream>
using namespace std;
void heapify(int *arr,int i,int n)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<n&&arr[l]>arr[i])
    {
        largest=l;
    }
    if(r<n&&arr[r]>arr[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
    heapify(arr,largest,n);
    }

}
void heapsort(int *arr,int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,i,n);
    }
    int heapsize=n;
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapsize--;
        heapify(arr,0,heapsize);
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

    heapsort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
