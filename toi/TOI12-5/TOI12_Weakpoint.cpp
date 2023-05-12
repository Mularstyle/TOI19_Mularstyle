#include<bits/stdc++.h>
using namespace std;
#define MX 500005
int N,M;
vector<int> V[MX];
vector<int> W(MX,0);
bool vis[MX],dvis[MX];
int mac=0,node=MX,par;
int dfs(int u)
{
    //if(u==par)return 0;
    //if(u==M)return 0;
    vis[u]=true;
    int sum=1;
    bool ch=false;
    for(auto v:V[u])
    {
        if(v==M)ch=true;
        if(vis[v])continue;
        int cnt=dfs(v);
        if(cnt==0)ch=true;
        sum+=cnt;
    }
    //cout<<u<<" HELP "<<sum<<"\n";
    W[u]=sum;
    if(ch)
        return 0;
    else
        return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    int u,v;
    for(int i=0;i<N;i++)
    {
        cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    dfs(M);
    for(int i=1;i<=N;i++)
    {
        if(W[i]>mac)
        {
            mac=W[i];
            node=i;
        }
        else if(W[i]==mac)
            node=min(node,i);
    }
    cout<<node<<"\n"<<mac-1;
}
