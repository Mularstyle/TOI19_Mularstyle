#include<bits/stdc++.h>
using namespace std;
#define MX 1005
#define f first
#define s second
int N,M;
int di[]={-1,0,0,1};
int dj[]={0,-1,1,0};
string W[MX];
void flood()
{
    queue<pair<int,int>> Q;
    Q.push({0,0});
    while(!Q.empty())
    {
        int qi=Q.front().f;
        int qj=Q.front().s;
        Q.pop();
        W[qi][qj]='#';
        for(int k=0;k<4;k++)
        {
            int ki=qi+di[k];
            int kj=qj+dj[k];
            if(ki>=0&&ki<N&&kj>=0&&kj<M&&W[ki][kj]=='.')
            {
                W[ki][kj]='#';
                Q.push({ki,kj});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>W[i];
    flood();
    vector<vector<bool>> vis(MX,vector<bool>(MX,false));

    int mac=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int cnt=0;
            if(!vis[i][j]&&W[i][j]=='X')
            {
                queue<pair<int,int>> Q;
                Q.push({i,j});
                while(!Q.empty())
                {

                    int qi=Q.front().f;
                    int qj=Q.front().s;
                    vis[qi][qj]=true;
                    Q.pop();
                    for(int k=0;k<4;k++)
                    {
                        int ki=qi+di[k];
                        int kj=qj+dj[k];
                        if(ki>=0&&ki<N&&kj>=0&&kj<M&&W[ki][kj]=='#')
                        {
                            cnt++;
                        }
                        else if(ki>=0&&ki<N&&kj>=0&&kj<M&&W[ki][kj]=='X'&&!vis[ki][kj])
                        {
                            vis[ki][kj]=true;
                            Q.push({ki,kj});
                        }
                    }
                }
            }
            mac=max(mac,cnt);
        }
    }
    cout<<mac;
}
