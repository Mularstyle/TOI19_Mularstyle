#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define f first
#define s second
vector<bool> vis(80005,false);
vector<pi> V[80005];
vector<ll> dp(80005,0);
int cnt=1,n;
void dfs(int u)
{
    if(vis[u])return;
    vis[u]=true;
    for(auto v:V[u])
    {
        if(!vis[v.s])
        {
        dfs(v.s);
        dp[cnt]=v.f;
        cnt++;

        }
    }
}
bool sol(ll m)
{
    int cn=0;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=dp[i];
        if(sum>=m)
        {
            cn++;
            sum=0;
        }
    }
    return cn>=3;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int u,v,w;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>u>>v>>w;
        V[u].push_back({w,v});
        V[v].push_back({w,u});
    }
    int start=0;
    for(int i=0;i<=n;i++)
    {
        if(V[i].size()==1)
        {
            start=i;
            break;
        }
    }
    dfs(start);

    ll l=0,r=LONG_MAX;
    while(l<r)
    {
        ll m=l+(r-l)/2;
        if(sol(m))
            l=m+1;
        else{
            r=m;

        }
    }
    cout<<l-1;


}
