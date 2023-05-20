#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[5005][5005];
ll a[5005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][i]=a[i];
    }

    for(int sz=2;sz<=n;sz++)
    {
        for(int i=1;i+sz-1<=n;i++)
        {
            int j=i+sz-1;
            dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j])+abs(a[i]-a[j]);
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[1][i]=max(dp[1][i],dp[1][j]+dp[j+1][i]);
        }
    }
    cout<<dp[1][n];
}
