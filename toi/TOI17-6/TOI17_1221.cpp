#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<pair<ll,ll>>> V(501,vector<pair<ll,ll>>(501,{0,1}));
    int n,m,q;
    cin>>n>>m>>q;
    ll u,v,w;
    for(int i=1;i<=n;i++)
    {
        cin>>V[i][i].f;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            V[i][j].f=V[i][i].f+V[j][j].f;
            V[i][j].s=2;
        }
    }


    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        V[u][v].f=min(w,V[u][v].f);
        V[v][u].f=min(w,V[v][u].f);
        V[u][v].s=2;
        V[v][u].s=2;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)continue;
                if(V[i][j].f>V[i][k].f+V[k][j].f)
                {
                V[i][j].f=V[i][k].f+V[k][j].f;
                V[i][j].s=V[i][k].s+V[k][j].s;
                }
                else if(V[i][j].f==V[i][k].f+V[k][j].f)
                {
                V[i][j].s=max(V[i][j].s,V[i][k].s+V[k][j].s);
                }
            }
        }
    }
    int a,b;
    for(int i=0;i<q;i++)
    {
        cin>>a>>b;
        cout<<V[a][b].f<<" "<<V[a][b].s<<"\n";
    }

}
