#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define MXN 105
#define MXF 105
int dis[2][MXF][MXN];
int p[MXN];
bool vis[2][MXF][MXN];
int N,S,D,F,M;
struct node{
    int u,d,fu,c;
    bool operator<(const node &b)const{
    return d>b.d;
    }
};
vector<pair<int,int>> V[MXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>p[i];
    cin>>S>>D>>F>>M;
    int u,v,w;
    for(int i=0;i<M;i++)
    {
        cin>>u>>v>>w;
        V[u].push_back({w,v});
        V[v].push_back({w,u});
    }

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<MXF;j++)
        {
            for(int k=0;k<MXN;k++)
            {
                dis[i][j][k]=INT_MAX;
                vis[i][j][k]=false;
            }
        }
    }
    priority_queue<node> Q;
    Q.push({S,0,0,0});
    dis[0][0][S]=0;

    while(!Q.empty())
    {
        node a=Q.top();
        Q.pop();
        if(vis[a.c][a.fu][a.u])continue;
        vis[a.c][a.fu][a.u]=true;

        if(a.c==0&&a.fu<F)
        {
            if(!vis[1][F][a.u]&&dis[1][F][a.u]>a.d)
            {
                dis[1][F][a.u]=a.d;
                Q.push({a.u,a.d,F,1});
            }
        }
        if(a.fu<F)
        {
            if(!vis[a.c][a.fu+1][a.u]&&dis[a.c][a.fu+1][a.u]>a.d+p[a.u])
            {
                dis[a.c][a.fu+1][a.u]=a.d+p[a.u];
                Q.push({a.u,a.d+p[a.u],a.fu+1,a.c});
            }
        }
        for(auto v:V[a.u])
        {
            if(v.f<=a.fu&&!vis[a.c][a.fu-v.f][v.s]&&dis[a.c][a.fu-v.f][v.s]>a.d)
            {
                dis[a.c][a.fu-v.f][v.s]=a.d;
                Q.push({v.s,a.d,a.fu-v.f,a.c});
            }
        }

    }
    cout<<dis[1][F][D];
}
/*
4
7 1 8 10
1 4 100
5
1 2 60
1 3 50
1 4 90
2 4 30
3 4 20
*/
