#include<bits/stdc++.h>
using namespace std;
int my[]= {-1,0,0,1};
int mx[]= {0,-1,1,0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,x,y;
    cin>>m>>x>>y;
    int mt[m+1][m+1];
    bool vis[m+1][m+1];
    memset(vis,false,sizeof(vis));
    memset(mt,100,sizeof(mt));
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>mt[i][j];
        }
    }
    int mac=mt[y][x];
    queue<int> sx,sy;
    sx.push(x);
    sy.push(y);
    while(!sx.empty())
    {
        x=sx.front();
        y=sy.front();
        sx.pop();
        sy.pop();
        for(int k=0; k<4; k++)
        {
            int tx=x+mx[k];
            int ty=y+my[k];
            if(tx>0&&ty>0&&tx<=m&&ty<=m&&!vis[ty][tx]&&mt[y][x]<mt[ty][tx]&&mt[ty][tx]!=100)
            {
                vis[ty][tx]=true;
                mac=max(mac,mt[ty][tx]);
                sx.push(tx);
                sy.push(ty);
            }
        }
    }
    cout<<mac;
}

