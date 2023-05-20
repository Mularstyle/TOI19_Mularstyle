#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pi> V[n+5];
    vector<int> dis(n+5,INT_MAX);
    vector<bool> vis(n+5,false);

    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        V[u].push_back({w,v});
        V[v].push_back({w,u});

    }
    priority_queue<pi,vector<pi>,greater<pi>> Q;
    int src,dst,trav;
    cin>>src>>dst>>trav;
    dis[src]=0;
    Q.push({0,src});

    while(!Q.empty())
    {
        pi p=Q.top();
        Q.pop();
        u=p.second;
        if(vis[u])continue;
        vis[u]=true;

        for(auto v:V[u])
        {
            if(vis[v.s])continue;
            int nd=ceil((float)trav/(v.f-1));
            nd=max(nd,dis[u]);
            if(dis[v.s]>nd)
            {
                dis[v.s]=nd;
                Q.push({dis[v.s],v.s});

            }

        }

    }
    cout<<dis[dst];
}
