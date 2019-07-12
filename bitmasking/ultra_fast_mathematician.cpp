#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
char a[101],b[101];
cin>>a>>b;
char c[101];
for(int i=0;a[i]!='\0';i++)
{
if(a[i]!=b[i])
c[i]='1';
else
c[i]='0';
}
cout<<c<<endl;
}
}
