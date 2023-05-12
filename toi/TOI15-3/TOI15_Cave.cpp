#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 2005
#define f first
#define s second
vector<pair<ll,ll>> V[MX];
vector<vector<bool>> vis(MX,vector<bool>(MX,false));
vector<pair<ll,ll>> ans;
ll dis[MX][MX];
ll N,P,U,E;
struct node{
    ll u,d,c;
    bool operator<(const node &b)const
    {
        return d>b.d;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>P>>U>>E;
    ll q,r,t;
    for(int i=0;i<E;i++)
    {
        cin>>q>>r>>t;
        V[q].push_back({t,r});
    }
    for(int i=0;i<MX;i++)
    {
        for(int j=0;j<MX;j++){
            dis[i][j]=LLONG_MAX;
        }
    }
    dis[P][0]=0;
    priority_queue<node> Q;
    Q.push({P,0,0});
    while(!Q.empty())
    {
        node cur=Q.top();
        Q.pop();
        if(vis[cur.u][cur.c])continue;
        vis[cur.u][cur.c]=true;
        if(cur.u==U)
        {
            ans.push_back({cur.d,cur.c});
        };
        for(auto v:V[cur.u])
        {
            if(cur.c<N&&dis[v.s][cur.c+1]>cur.d+v.f&&dis[v.s][cur.c]>cur.d+v.f)
            {
                dis[v.s][cur.c+1]=cur.d+v.f;
                Q.push({v.s,dis[v.s][cur.c+1],cur.c+1});
            }
        }
    }
    int L,l;
    cin>>L;
    while(L--)
    {
        cin>>l;
        ll mn=LLONG_MAX;
        for(auto v:ans)
        {

                mn=min(v.f+(v.s-1)*l,mn);
        }
        cout<<mn<<" ";
    }

}
