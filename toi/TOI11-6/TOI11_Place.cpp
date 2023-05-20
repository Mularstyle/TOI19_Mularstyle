#include<bits/stdc++.h>
using namespace std;
int par[200005];
#define ll long long
int getpar(int u)
{
    if(u==par[u])
        return u;
    return par[u]=getpar(par[u]);
}
struct node{
    int u,v,w;
    bool operator<(const node &b)const{
        return w<b.w;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    priority_queue<node> Q;
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        Q.push({u,v,w});
    }
    ll sum=0;
    for(int i=0;i<200005;i++)
        par[i]=i;
    while(!Q.empty())
    {
        int u=Q.top().u;
        int v=Q.top().v;
        int w=Q.top().w;
        Q.pop();
        if(getpar(u)==getpar(v))continue;
        par[getpar(u)]=par[getpar(v)];
        sum+=w-1;
    }
    cout<<sum;
}
