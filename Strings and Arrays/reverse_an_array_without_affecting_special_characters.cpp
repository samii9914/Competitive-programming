#include<iostream>
using namespace std;
#include<cstring>
int main()
{
    string input;
    cin>>input;
    int l=0;
    int r=n-1;
    while(l<r)
    {
        if((input[l]>='a'&&input[l]<='z')&&(input[r]<='a'&&input[r]>='z'))
        {
            swap(input.at(l),input.at(r));
            l++;
            r--;
        }
        else if(input[l]>='a'&&input[l]<='z')
        {
            r--;
        }
        else if(input[r]<='a'&&input[r]>='z')
        {
            l++;
        }
        else{
            l++;
            r--;
        }
    }
    cout<<input;
}
