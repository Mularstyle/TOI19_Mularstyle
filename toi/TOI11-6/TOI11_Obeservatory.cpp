#include<bits/stdc++.h>
using namespace std;
    #define ll long long
    ll dl[2005][2005],sl[2005][2005];
    ll dr[2005][2005],sr[2005][2005];
    ll ar[2005][2005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>ar[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sl[i][j]=ar[i][j]+sl[i-1][j]+sl[i][j-1]-sl[i-1][j-1];
            dl[i][j]=dl[i-1][j-1]+sl[i][j]-sl[i-1][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            sr[i][j]=ar[i][j]+sr[i-1][j]+sr[i][j+1]-sr[i-1][j+1];
            dr[i][j]=dr[i-1][j+1]+sr[i][j]-sr[i-1][j];
        }
    }

    ll mac=LLONG_MIN;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {

                int sz=k;
                ll a,b;
                a=b=mac;
                if(j-sz>=0&&i-sz>=0)
                 a=dl[i][j]-dl[i-sz][j-sz]-sl[i][j-sz]+sl[i-sz][j-sz];
                if(j+sz<=m+1&&i-sz>=0)
                 b=dr[i][j]-dr[i-sz][j+sz]-sr[i][j+sz]+sr[i-sz][j+sz];
                mac=max({mac,a,b});
               // cout<<i<<" "<<j<<" "<<sz<<" "<<a<<" "<<b<<" "<<mac<<"\n";

        }
    }
    cout<<mac;

}
/*
4 5 3
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/
