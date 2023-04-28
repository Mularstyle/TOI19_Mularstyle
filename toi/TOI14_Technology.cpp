#include<bits/stdc++.h>
using namespace std;
vector<int> V[100005];
vector<int> tech[100005];
vector<int> vis(100005,0);
int cnt=0;
bool dfs(int u)
{
    if(vis[u]==2)
        return false;
    if(vis[u]==1)
        return true;
    vis[u]=1;
    cnt++;
    for(auto v:V[u])
    {
        if(dfs(v))
            return true;
    }
    vis[u]=2;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,t;
    cin>>n>>k>>t;
    int l,p,q;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>p;
        tech[l].push_back(i);
        for(int j=1;j<=p;j++)
        {
            cin>>q;
            V[i].push_back(q);
        }
    }
    int ans=-1;
    for(int i=1;i<=k;i++)
    {
        for(auto v:tech[i])
        {
            if(vis[v])continue;
            if(dfs(v))
            {
                cout<<ans;
                return 0;
            }

        }
        if(cnt<=t)ans=i;
    }
    cout<<ans;
    return 0;
}
