#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    char ar[n+1];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    for(int sz=2;sz<=n;sz++)
    {
        for(int i=0;i<=n-sz;i++)
        {
            int j=i+sz-1;
            if(ar[i]==ar[j])
            {
                dp[i][j]=dp[i+1][j-1]+1;
            }
            else
            {
                for(int k=i;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }

    cout<<dp[0][n-1];
}
