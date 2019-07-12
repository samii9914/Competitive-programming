#include<iostream>
using namespace std;
#include<vector>
int main()
{
    vector<int> a;
    int n;
    int temp=n;
    cin>>n;
    int arr[temp+1]={0};
    for(int i=0;i<temp+1;i++)
    {
        if(arr[i]==0)
        {
            arr[i]=i;
        }
        for(int j=2*i;j<temp+1;j=j+i)
        {
            if(arr[j]==0)
            {
              arr[j]=i;
            }

        }
    }
    while(n!=1)
    {
       a.push_back(arr[n]);
       n=n/arr[n];
    }
    int ans=temp;
    for(int i=0;i<a.size();i++)
    {
        temp=temp*(1-(1/a.at(i)));
    }

    cout<<temp;

}
