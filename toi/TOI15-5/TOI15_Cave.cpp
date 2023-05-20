#include<bits/stdc++.h>
using namespace std;
#define mxn 2005
#define ll long long
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define s second
int n,p,j,e,l;
ll dis[mxn][mxn];
bool vis[mxn][mxn]={false};
vector<pi> V[mxn];
vector<pi> ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>p>>j>>e;
    ll u,v,w;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v>>w;
        V[u].push_back({w,v});
    }
    for(int i=0; i<mxn; i++)
    {
        for(int k=0; k<mxn; k++)
            dis[i][k]=LLONG_MAX;
    }
    dis[0][p]=0;
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    Q.push({0,{0,p}});
    while(!Q.empty())
    {
        pii c=Q.top();
        u=c.s.s;
        ll x=c.s.f;
        Q.pop();
        if(vis[x][u])continue;
        vis[x][u]=true;
        if(u==j)
        {
            ans.push_back({c.f,x});
        }
        for(auto [d,v]:V[u])
        {
            if(x<n&&!vis [x+1][v]&&dis[x][v]>dis[x][u]+d&&dis[x+1][v]>dis[x][u]+d)
            {
                dis [x+1][v]=dis[x][u]+d;
                Q.push({dis [x+1][v],{x+1,v}});
            }
        }
    }
    ll l;
    cin>>l;
    while(l--)
    {
        cin>>w;
        ll mac=LLONG_MAX;
        for(auto [d,x]:ans)
        {
            mac=min(mac,d+(x-1)*w);
        }
        cout<<mac<<" ";
    }
}
