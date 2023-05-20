#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
bool vis[3000][3000];
int dis[3000][3000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    string s[n];
    memset(dis,0,sizeof(dis));
    queue<pair<int,int>> Q;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='X')
            {
                Q.push({i,j});
                vis[i][j]=true;
                dis[i][j]=0;
            }
        }
    }
    int cnt=0;
    int sum=0;
    while(!Q.empty())
    {
        int qi=Q.front().first;
        int qj=Q.front().second;
        Q.pop();
        if(s[qi][qj]=='A')
        {
            cnt++;
            sum+=dis[qi][qj]*2;
        }
        int di[]= {-1,0,0,1};
        int dj[]= {0,-1,1,0};
        for(int k=0; k<4; k++)
        {
            int ki=qi+di[k];
            int kj=qj+dj[k];
            if(ki>=0&&ki<n&&kj>=0&&kj<m&&!vis[ki][kj]&&s[ki][kj]!='W')
            {
                dis[ki][kj]=dis[qi][qj]+1;
                vis[ki][kj]=true;
                Q.push({ki,kj});
            }
        }
    }
    if(cnt==0)
        cout<<"0";
    else
        cout<<cnt<<" "<<sum;
}
