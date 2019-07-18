#include<iostream>
using namespace std;
void merge(int s,int mid,int e,int *arr)
{
    int M=mid-s+1;
    int N=e-mid;
    int left[M];
    int right[N];

    for(int i=0;i<M;i++)
    {
        left[i]=arr[i+s];
    }

    for(int i=0;i<N;i++)
    {
        right[i]=arr[i+mid+1];
    }

    int i=0;
    int j=0;
    int k=0;
    int ans[N+M+1];
    while(i<M&&j<N)
    {
       if(left[i]<right[j])
       {
           ans[k]=left[i];
           i++;
           k++;
       }
       else
       {
           ans[k]=right[j];
           k++;
           j++;
       }
    }
    while(i<M)
    {
        ans[k]=left[i];
        i++;
        k++;
    }

    while(j<N)
    {
        ans[k]=right[j];
        j++;
        k++;
    }

    for(int i=s;i<=e;i++)
    {
        arr[i]=ans[i-s];
    }
}
void mergesort(int *arr,int s,int e)
{
    if(s<e)
    {
     int mid=(s+e)/2;
     mergesort(arr,s,mid);
     mergesort(arr,mid+1,e);
     merge(s,mid,e,arr);
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

    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
