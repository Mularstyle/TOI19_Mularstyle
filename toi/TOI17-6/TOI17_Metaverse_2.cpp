#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define ll long long
#define MX 20005
using namespace std;
int N,M,P,K;
int dis[18][MX];

int NODE[4][MX];
int distance(int a,int b)
{
    return abs(NODE[2][a]-NODE[0][b])+abs(NODE[3][a]-NODE[1][b]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K>>P;
    int wi,wj,oi,oj;
    NODE[0][0]=NODE[1][0]=NODE[2][0]=NODE[3][0]=1;
    for(int i=1;i<=K;++i)
    {
        cin>>NODE[0][i]>>NODE[1][i]>>NODE[2][i]>>NODE[3][i];

    }
    NODE[0][K+1]=NODE[2][K+1]=N;
    NODE[1][K+1]=NODE[3][K+1]=M;

    for(int i=0;i<18;++i)
    {
        for(int j=0;j<MX;++j)
        {
            dis[i][j]=2345678;
        }
    }
    dis[0][0]=0;
    for(int i=1;i<=K+1;++i)
        dis[0][i]=distance(0,i);
    for(int p=1;p<=P;++p)
    {
        for(int i=1;i<=K;++i)
        {
            for(int j=1;j<=K+1;++j)
            {
                dis[p][j]=min(dis[p][j],dis[p-1][i]+distance(i,j));
            }
        }
    }
    int mac=INT_MAX,warp=0;
    for(int i=0;i<=P;++i)
    {
        if(dis[i][K+1]<mac)
        {
            mac=dis[i][K+1];
            warp=i;
        }
    }
    cout<<mac<<" "<<warp;
}
