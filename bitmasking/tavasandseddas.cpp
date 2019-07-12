#include<iostream>
using namespace std;
#include<string.h>
int main()
{
    char a[20];
    cin>>a;
    int len=strlen(a);
    int ans=(1<<len)-2;

    int pos=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]=='7')
        {
            ans=ans+(1<<pos);
        }
        pos++;
    }
    cout<<ans;
}
