#include<iostream>
using namespace std;
#include<bits/stdc++.h>
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

    int l=0;
    int h=n-1;
    while(l<=h)
    {
        int pos=l+((double)(h-l)/(arr[h]-arr[l])*(key-arr[l]));
        if(arr[pos]==key)
        {
            cout<<"Position found at index "<<pos;
            return 0;
        }
        else if(arr[pos]>key)
        {
            h--;
        }
        else{
            l++;
        }
    }

    cout<<"Element not found"<<endl;
}
