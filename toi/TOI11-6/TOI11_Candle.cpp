#include<bits/stdc++.h>
using namespace std;
#define MX 2005
#define pi pair<int,int>
#define f first
#define s second
int C[MX][MX];
bool vis[MX][MX];
int N,M;
int di[]={-1,-1,-1,0,0,1,1,1};
int dj[]={-1,0,1,-1,1,-1,0,1};

void bfs(int fi,int fj)
{
    queue<pi> Q;
    Q.push({fi,fj});
    while(!Q.empty())
    {
        int qi=Q.front().f;
        int qj=Q.front().s;
        Q.pop();
        for(int k=0;k<8;k++)
        {
            int ki=qi+di[k];
            int kj=qj+dj[k];
            if(ki>0&&ki<=N&&kj>0&&kj<=M&&!vis[ki][kj]&&C[ki][kj]==1)
            {
                vis[ki][kj]=true;
                Q.push({ki,kj});
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(vis,false,sizeof(vis));
    cin>>N>>M;
    string s;
    for(int i=1;i<=N;i++)
    {
        cin>>s;
        for(int j=1;j<=M;j++)
        {
            C[i][j]=s[j-1]-'0';
        }
    }
    int cnt=0;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(!vis[i][j]&&C[i][j]==1)
            {
                cnt++;
                bfs(i,j);
            }
        }
    }
    cout<<cnt;
}
