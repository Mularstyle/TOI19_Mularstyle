#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[5005][5005],d[5005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>d[i];
        dp[i][i]=d[i];
        }

    for(int sz=2;sz<=n;sz++)
    {
        for(int l=1;l<=n-sz+1;l++)
        {
            int r=sz+l-1;
            dp[l][r]=max(dp[l+1][r]+d[l],dp[l][r-1]+d[r])+abs(d[l]-d[r]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[1][i]=max(dp[1][i],dp[1][j]+dp[j+1][i]);
        }
    }
    cout<<dp[1][n];

}
