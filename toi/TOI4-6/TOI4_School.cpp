#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

char school[65][65];
bool vis[65][65];
int dp[65][65];
int n,m;
int bfs(int ii,int jj,int sz)
{
    memset(vis,false,sizeof(vis));
    int cnt=0;
    for(int i=ii;i>ii-sz;i--)
    {
        for(int j=jj;j>jj-sz;j--)
        {
        if(school[i][j]=='P'&&!vis[i][j])
        {
            cnt++;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            while(!Q.empty())
            {
                int qi=Q.front().f;
                int qj=Q.front().s;
                Q.pop();
                int di[]={-1,0,0,1};
                int dj[]={0,-1,1,0};
                for(int k=0;k<4;k++)
                {
                    int ki=qi+di[k];
                    int kj=qj+dj[k];
                    if(ki>0&&ki<=n&&kj>0&&kj<=m&&!vis[ki][kj]&&school[ki][kj]=='P')
                    {
                        vis[ki][kj]=true;
                        Q.push({ki,kj});
                    }
                }
            }

        }

        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            cin>>school[i][j];
            if(school[i][j]!='T')dp[i][j]=1;
            dp[i][j]=dp[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }

    int mac=0,pon=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int sz=min(i,j);sz>0;sz--)
            {
                if(dp[i][j]+dp[i-sz][j-sz]-dp[i-sz][j]-dp[i][j-sz]!=(sz)*(sz))continue;
                //cout<<i<<" "<<j<<" "<<sz<<"\n";
                if(sz>mac)
                {
                    mac=sz;
                    pon=bfs(i,j,sz);
                }
                else if(mac==sz)
                {
                    pon=min(pon,bfs(i,j,sz));
                }


            }
        }
    }
    cout<<mac*mac<<" "<<pon;

}
