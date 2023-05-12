#include<bits/stdc++.h>
using namespace std;
#define MX 80005
#define ll long long
#define f first
#define s second
vector<pair<ll,ll>> V[MX];
vector<ll> profit(MX);
vector<bool> vis(MX,false);
ll N,cnt=0;
void dfs(ll u)
{
    vis[u]=true;
    for(auto v:V[u])
    {
        if(!vis[v.s])
        {

            dfs(v.s);
            profit[cnt]=v.f;
            cnt++;
        }
    }
}
bool check(ll m)
{
    ll cntf=0;
    ll sum=0;
    for(int i=0;i<cnt;i++)
    {
        sum+=profit[i];
        if(sum>=m)
        {
            sum=0;
            cntf++;
        }
        //cout<<sum<<"\n";
    }
    return cntf>=3;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    ll u,v,l,r;
    for(int i=0;i<N;i++)
    {
        cin>>u>>v>>l;
        V[u].push_back({l,v});
        V[v].push_back({l,u});
    }
    for(int i=0;i<=N;i++)
    {
        if(V[i].size()==1)
        {
            dfs(i);
            break;
        }
    }
    l=0,r=LLONG_MAX;
    while(l<r)
    {
        ll m=l+(r-l)/2;
        if(check(m))
            l=m+1;
        else
            r=m;

    }

    cout<<l-1;
}
