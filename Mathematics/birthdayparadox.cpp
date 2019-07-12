#include<iostream>
using namespace std;
int main()
{
    float prob;
    cin>>prob;
    float p=1;
    float num=365;
    float denom=365;
    int people=0;
    while(p>=1-prob)
    {
        p=p*(num/denom);
        num--;
        people++;
    }

    cout<<people<<endl;
}

qww
