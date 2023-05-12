#include<bits/stdc++.h>
using namespace std;

int ar[5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        int d=n+1;
        while(d>=100)ar[4]++,d-=100;
        while(d>=90)ar[4]++,ar[2]++,d-=90;
        while(d>=50)ar[3]++,d-=50;
        while(d>=40)ar[3]++,ar[2]++,d-=40;
        while(d>=10)ar[2]++,d-=10;
        while(d>=9)ar[2]++,ar[0]++,d-=9;
        while(d>=5)ar[1]++,d-=5;
        while(d>=4)ar[1]++,ar[0]++,d-=4;
        while(d>=1)ar[0]++,d--;
    }
    for(int i=0;i<5;i++)
        cout<<ar[i]<<" ";
}
