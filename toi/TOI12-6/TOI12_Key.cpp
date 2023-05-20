#include<bits/stdc++.h>
using namespace std;

string A,B,temp;
int n,m;
bool dp[1005][1005];
bool vis[1005][1005];
bool otk(int a,int b,int idx)
{
    if(idx==temp.length())
    {
        return true;
    }
    if(vis[a][b])
    {
        return dp[a][b];
    }
    bool ch=false;
    if(a<n&&b<m&&A[a]!=temp[idx]&&B[b]!=temp[idx]){
        vis[a][b]=true;
        return dp[a][b]=false;
    }
     if(a<n&&A[a]==temp[idx]){
        vis[a][b]=true;
        dp[a][b]|=otk(a+1,b,idx+1);
        ch|=dp[a][b];
     }
     if(b<m&&B[b]==temp[idx]){
        vis[a][b]=true;
        dp[a][b]|=otk(a,b+1,idx+1);
        ch|=dp[a][b];
     }
    return ch;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>A>>B;
    n=A.length();
    m=B.length();
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        memset(dp,0,sizeof(dp));
        memset(vis,false,sizeof(vis));
        cin>>temp;
        if(otk(0,0,0))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
