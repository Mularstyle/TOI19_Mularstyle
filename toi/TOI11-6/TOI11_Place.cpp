#include<bits/stdc++.h>
using namespace std;
#define MX 200005
#define ll long long
int par[MX];
int getpar(int u)
{
    if(par[u]==u)
        return u;
    return par[u]=getpar(par[u]);
}
struct edge{
    int u,v,w;
    bool operator<(const edge &b)const{
        return w<b.w;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;

    priority_queue<edge> Q;
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        Q.push({u,v,w-1});
    }
    for(int i=0;i<MX;i++)
        par[i]=i;

    ll sum=0;
    int cnt=0;
    while(!Q.empty()&&cnt<n-1)
    {
        edge c=Q.top();
        Q.pop();
        if(getpar(c.u)==getpar(c.v))continue;
        par[getpar(c.u)]=par[getpar(c.v)];
        cnt++;
        sum+=c.w;
        //cout<<c.w<<"\n";
    }
    cout<<sum;
}
