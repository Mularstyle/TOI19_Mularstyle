#include<bits/stdc++.h>
using namespace std;
#define MXL 10005
#define MXN 100005
int N,K,T,cnt=0;
vector<int> L[MXL];
vector<int> V[MXN];
vector<int> vis(MXN,0);
bool dfs(int u)
{
    ///true = no cycle
    if(vis[u]==1)return false;
    if(vis[u]==2)return true;
    vis[u]=1;
    cnt++;
    for(auto v:V[u])
    {
        if(!dfs(v))return false;
    }
    vis[u]=2;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>K>>T;
    int l,p,q;
    for(int i=1;i<=N;i++)
    {
        cin>>l>>p;
        L[l].push_back(i);
        for(int j=0;j<p;j++)
        {
            cin>>q;
            V[i].push_back(q);
        }
    }
    int ans=-1;
    for(int i=1;i<=K;i++)
    {
        bool ch=true;
        for(auto v:L[i])
        {
            if(vis[v])continue;
            ch&=dfs(v);
        }
        if(ch&&cnt<=T)ans=i;
        else break;
    }
    cout<<ans;
}

