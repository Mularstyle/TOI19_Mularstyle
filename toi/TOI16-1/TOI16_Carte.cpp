#include<bits/stdc++.h>
using namespace std;
map<vector<int>,int> dp;
int n,k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int mac=0;
    for(int i=0;i<n;i++)
    {
        int nn;
        cin>>nn;
        int ar[nn];
        int dp[nn][nn];

        for(int i=0;i<nn;i++){
            cin>>ar[i];
        }

         for(int i=0;i<nn;i++)
        {
            for(int j=0;j<nn;j++)
                dp[i][j]=INT_MAX;
        }
        for(int i=0;i<nn;i++)
            dp[i][i]=1;

        for(int sz=2;sz<=nn;sz++)
        {
            for(int l=0;l<nn&&l+sz<=nn;l++)
            {
                int r=l+sz-1;
                for(int k=l;k<r;k++)
                {
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
                }
                if(ar[l]==ar[r])
                    dp[l][r]--;
            }
        }
    mac=max(mac,dp[0][nn-1]);

    }
    cout<<mac;
}
/*
3 5
12
7 2 6 6 6 6 6 6 6 6 6 6
10
5 2 5 7 3 8 3 1 2 7
5
8 8 4 4 4
*/
