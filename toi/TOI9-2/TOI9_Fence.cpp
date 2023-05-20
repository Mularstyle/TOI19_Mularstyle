#include<bits/stdc++.h>
using namespace std;

int qs[505][505];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,t;
    cin>>n>>m>>t;
    int a,b,ans=0;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        qs[a+1][b+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            {
                qs[i][j]=qs[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
            }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int sz=min(n,m);sz>=2;sz--)
            {
                if(i-sz<0||j-sz<0)continue;
                int sum=qs[i][j]-qs[i-sz][j]-qs[i][j-sz]+qs[i-sz][j-sz];

                sum=sum-qs[i-1][j-1]+qs[i-1][j-sz+1]+qs[i-sz+1][j-1]-qs[i-sz+1][j-sz+1];

                if(sum==0)
                {
                    //cout<<sz<<" "<<i<<" "<<j<<"\n";
                    ans=max(ans,sz);
                    break;
                }
            }
        }
    }
    cout<<ans<<"\n";
    ans=0;
    cin>>n>>m>>t;
    memset(qs,0,sizeof(qs));
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        qs[a+1][b+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            {
                qs[i][j]=qs[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
            }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int sz=min(n,m);sz>=2;sz--)
            {
                if(i-sz<0||j-sz<0)continue;
                int sum=qs[i][j]-qs[i-sz][j]-qs[i][j-sz]+qs[i-sz][j-sz];

                sum=sum-qs[i-1][j-1]+qs[i-1][j-sz+1]+qs[i-sz+1][j-1]-qs[i-sz+1][j-sz+1];

                if(sum==0)
                {
                    //cout<<sz<<" "<<i<<" "<<j<<"\n";
                    ans=max(ans,sz);
                    break;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
