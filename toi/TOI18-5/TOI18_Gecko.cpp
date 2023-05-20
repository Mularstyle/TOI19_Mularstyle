#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define pi pair<ll,ll>
#define pii pair<ll,pi>
stack<pi> ans;
    vector<ll> dis(20005,LONG_MAX);
    vector<bool> vis(20005,false);
    vector<ll> G(20005);
    vector<pi> V[20005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N,M,K,P;
    cin>>N>>M>>K>>P;

    for(int i=0;i<K;i++)
        cin>>G[i];
    ll u,v,w;
    for(int i=0;i<M;i++)
    {
        cin>>u>>v>>w;
        V[u].push_back({w,v});
        V[v].push_back({w,u});
    }

    priority_queue<pii,vector<pii>,greater<pii>> Q;
    Q.push({0,{P,-1}});
    dis[P]=0;
    while(!Q.empty())
    {
        u=Q.top().s.f;
        w=Q.top().s.s;
        Q.pop();
        if(vis[u])continue;
        vis[u]=true;

        if(w>=0)
            ans.push({min(w,u),max(w,u)});

        for(auto [d,v] : V[u])
        {
            if(!vis[v]&&dis[v]>dis[u]+d)

            {
                dis[v]=dis[u]+d;
                Q.push({dis[v],{v,u}});
            }
        }
    }
    for(int i=0;i<K;i++)
        cout<<dis[G[i]]<<" ";
    cout<<"\n"<<ans.size()<<"\n";

    while(!ans.empty())
    {
        cout<<ans.top().f<<" "<<ans.top().s<<"\n";
        ans.pop();
    }


}
