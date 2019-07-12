#include<iostream>
using namespace std;
#define ll long long int
bool isvalidconf(ll books[],ll m,ll n,ll index)
{
    ll current_pages=0;
    ll students=1;
    for(int i=0;i<n;i++)
    {
        if(current_pages+books[i]>index)
        {
            current_pages=books[i];
            students++;
            if(students>m)
            {
                return 0;
            }
        }
        else{
            current_pages+=books[i];
        }
    }
    return 1;
}
ll binarysearchbooks(ll books[],ll m,ll n)
{
    ll s=books[n-1];
    ll total=0;
    ll ans=-1;
    for(int i=0;i<n;i++)
    {
        total=total+books[i];
    }
    ll e=total;
    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(isvalidconf(books,m,n,mid)==1)
           {
               ans=mid;
               e=mid-1;
           }
           else{
            s=mid+1;
           }
    }
    return ans;
}
int main()
{
    ll n;
    ll m;
    ll books[100005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>books[i];
    }
    cin>>m;
    cout<<binarysearchbooks(books,m,n);
}
