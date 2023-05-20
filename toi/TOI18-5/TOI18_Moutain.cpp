#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define MX 505
vector<vector<ll>> V(MX,vector<ll>(MX,MX));
vector<vector<ll>> dis(MX,vector<ll>(MX,LONG_MAX));
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N,M;
    cin>>N>>M;
    vector<pair<ll,ll>> node(N);
    for(int i=0; i<N; i++)
    {
        cin>>node[i].s>>node[i].f;
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            V[i][j]=abs(node[i].f-node[j].f)+abs(node[i].s-node[j].s);
    }
    for(int i=0; i<N; i++)
        dis[0][i]=abs(node[i].f-node[0].f)+abs(node[i].s-node[0].s);
    for(int k=1; k<N; k++)
    {
        for(int i=1; i<N-1; i++)
        {
            for(int j=1; j<N; j++)
            {
                dis[k][j]=min(dis[k][j],max(dis[k-1][i],V[i][j]));
            }
        }
    }
    ll sum=0;
    vector<ll> customer(M);
    for(int i=0; i<M; i++)
        cin>>customer[i];

    for(int i=0; i<M; i++)
    {
        ll l=0,r=N-1;
        while(l<r)
        {
            ll m=l+(r-l)/2;
            if(dis[m][N-1]>customer[i])
                l=m+1;
            else
                r=m;
        }
        sum+=l+1;
    }
    cout<<sum;
}
