#include<iostream>
using namespace std;
int main()
{
   int size;
   cin>>size;
   int arr[size];
   for(int i=0;i<size;i++)
   {
       cin>>arr[i];
   }

   int n=0;
   for(int i=0;i<n;i++)
   {
       n=n^arr[i];
   }

   int mask=1;
   while((n&mask)!=0)
   {
       mask=mask<<1;
   }

   int a=0,b=0;
   for(int i=0;i<size;i++)
   {
       if((mask^arr[i])==0)
       {
           b=b^arr[i];
       }
       else{
        a=a^arr[i];
       }
   }
   cout<<a<<" "<<b;
}
