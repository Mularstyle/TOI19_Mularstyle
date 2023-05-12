#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n,m;
int s[10005][2005];
bool vis[10005][2005];
int ans[3];
int di[]= {-1,0,0,1};
int dj[]= {0,-1,1,0};
int ai[]= {-1,-1,-1,0,0,1,1,1};
int aj[]= {-1,0,1,-1,1,-1,0,1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    string t;
    for(int i=0; i<n; i++)
    {
        cin>>t;
        for(int j=0; j<m; j++)
            s[i][j]=t[j]-'0';
    }
    memset(vis,false,sizeof(vis));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {

            if(!vis[i][j]&&s[i][j]==1)
            {
                queue<pair<int,int>> Q;
                Q.push({i,j});
                int cnt=0;
                vis[i][j]=true;
                while(!Q.empty())
                {
                    pair<int,int> p=Q.front();
                    Q.pop();

                    for(int k=0; k<4; k++)
                    {
                        int ki=p.f+di[k];
                        int kj=p.s+dj[k];
                        if(ki>=0&&ki<n&&kj>=0&&kj<m&&!vis[ki][kj]&& s[ki][kj]==1)
                        {
                            Q.push({ki,kj});
                            vis[ki][kj]=true;
                            //cout<<ki<<" "<<kj<<"\n";
                        }
                    }
                    int cntb=0;
                    for(int k=0; k<4; k++)
                    {
                        int ki=p.f+di[k];
                        int kj=p.s+dj[k];
                        if(ki<0||ki>=n||kj<0||kj>=m||s[ki][kj]==0)
                            cntb++;
                    }
                    if(cntb>=3){
                       // cout<<p.f<<" "<<p.s<<" "<<cntb<<"\n";
                        cnt++;
                    }
                    //cout<<p.f<<" "<<p.s<<"\n";

                }
                if(cnt==0)
                    ans[0]++;
                else if(cnt==4)
                    ans[1]++;
                else
                    ans[2]++;
               // cout<<cnt<<"\n";
            }
        }
    }
    for(int i=0; i<3; i++)
        cout<<ans[i]<<" ";
}
/*
20 12
00000000000000000000
00100000001111111110
01110000000111111100
11111000000011111000
00000000000001110000
00000000000000100000
00000000000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000
00011111000000000000
*/
