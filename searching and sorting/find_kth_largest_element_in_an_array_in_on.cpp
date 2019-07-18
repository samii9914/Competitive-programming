#include<iostream>
using namespace std;
void sort(int *arr,int n)
{
    int s=n;
    cout<<s<<endl<<endl;
    //counting sort
    int count[100];
    for(int i=0;i<100;i++)
    {
        count[i]=0;
    }

    for(int i=0;i<s;i++)
    {
        count[arr[i]]+=1;
    }
    for(int i=1;i<100;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    int ans[s];
    for(int i=s-1;i>=0;i--)
    {
        ans[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }

    for(int i=0;i<s;i++)
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

    int k;
    cin>>k;
    sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    cout<<arr[n-k];
}
