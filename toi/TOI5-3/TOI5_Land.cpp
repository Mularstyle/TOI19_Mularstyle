#include<bits/stdc++.h>
using namespace std;
double minc=2000000000;
int n,m;
double l[4][4];
bool vis[4][4];
int di[]={-1,0,1,-1,1,-1,0,1};
int dj[]={-1,-1,-1,0,0,1,1,1};

void buy(int cnt,double sum)
{
    if(cnt==n*m)
        minc=min(minc,sum);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j])
            {
            vis[i][j]=true;
            for(int k=0;k<8;k++)
            {
                int ki=i+di[k];
                int kj=j+dj[k];
                if(ki>=0&&ki<n&&kj>=0&&kj<m&&!vis[ki][kj])
                {
                    l[ki][kj]+=l[i][j]*(0.1);
                }

            }
            buy(cnt+1,sum+l[i][j]);
            for(int k=0;k<8;k++)
            {
                int ki=i+di[k];
                int kj=j+dj[k];
                if(ki>=0&&ki<n&&kj>=0&&kj<m&&!vis[ki][kj])
                {
                    l[ki][kj]-=l[i][j]*(0.1);
                }

            }
            vis[i][j]=false;

            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>l[i][j];
    }
    buy(0,0.0);
    printf("%.2f",minc);
}
