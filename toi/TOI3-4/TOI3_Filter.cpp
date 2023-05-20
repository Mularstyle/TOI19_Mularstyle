#include<bits/stdc++.h>
using namespace std;
int F[3333];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int W,H,n;
    cin>>W>>H;
    memset(F,0,sizeof(F));
    cin>>n;
    int x,a;
    for(int i=0; i<n; i++)
    {
        cin>>x>>a;
        for(int j=x; j<x+a&&j<W; j++)
        {
            F[j]+=1;
        }
    }
    int fp=0;//fivty
    int op=0;//onhun
    for(int i=0; i<W; i++)
    {
        if(F[i]==0)
            op++;
        else if(F[i]==1)
            fp++;
    }
    cout<<op*H<<" "<<fp*H;
}

