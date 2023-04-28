#include<bits/stdc++.h>
using namespace std;
#define MX 2005
#define ll long long
#define pl pair<ll,ll>
#define f first
#define s second
int N,P,U,E,L;
vector<pl> V[MX];
vector<pl> dis[MX];

void dijk()
{
    queue<pair<ll,pl>> Q;//{dis,{node,cnt}}
    for(int i=0;i<N;i++)dis[i].push_back({LONG_LONG_MAX,0});
    Q.push({0,{P,0}});
    dis[P].push_back({0,0});
    while(!Q.empty())
    {
        pair<ll,pl> u=Q.front();Q.pop();
       // cout<<"p";
        for(auto v:V[u.s.f])
        {
            //cout<<v.s<<" "<<dis[v.s].back().f<<"\n";
            if( dis[v.s].back().f > u.f + v.f )
            {
            //cout<<"c";
            dis[v.s].push_back( {u.f+v.f , u.s.s+1} );
            Q.push( {dis[v.s].back().f , { v.s , u.s.s+1 } } );
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>P>>U>>E;
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        V[u].push_back({w,v});
    }
    dijk();
    cin>>L;
    while(L--)
    {
        ll t;
        cin>>t;
        ll ans=LLONG_MAX;
        for(auto d : dis[U])
        {
            ans = min( ans , d.f + (d.s-1)*t );
        }
        cout<<ans<<" ";
    }
}
