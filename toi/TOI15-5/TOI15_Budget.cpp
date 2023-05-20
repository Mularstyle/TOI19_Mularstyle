#include<bits/stdc++.h>
using namespace std;
#define MXN 3005
#define f first
#define s second
int par[MXN];
int getpar(int u)
{
    if(u==par[u])
        return u;
    return par[u]=getpar(par[u]);
}
struct edge{
    int u,v,w;
    bool operator<(const edge &b)const{
        return w>b.w;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int B,E,P;
    int s,t,l,r;
    cin>>B>>E;
    int cnt=0;

    for(int i=0;i<MXN;i++)
        par[i]=i;
    vector<int> path;
    priority_queue<edge> Q;
    for(int i=0;i<E;i++)
    {
        cin>>s>>t>>l>>r;
        if(r==1)
        {
            if(getpar(s)==getpar(t))continue;
            par[getpar(s)]=par[getpar(t)];
            cnt++;
        }
        else
        {
            Q.push({s,t,l});
        }
    }
    while(!Q.empty()&&cnt<B-1)
    {
        edge c=Q.top();
        Q.pop();
        int u=c.u;
        int v=c.v;
        if(getpar(u)==getpar(v))continue;
        par[getpar(u)]=par[getpar(v)];
        path.push_back(c.w);
        cnt++;
    }

    cin>>P;
    vector<pair<int,int>> budget(P);
    for(int i=0;i<P;i++)
    {
        cin>>budget[i].s>>budget[i].f;
    }
    sort(budget.begin(),budget.end());
    long long cost=0;
    for(auto p:path)
    {
        for(int i=0;i<P;i++)
        {
            if(budget[i].s>=p)
            {
                cost+=budget[i].f;
                break;
            }
        }
    }
    cout<<cost;
}
