#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
map<pi,int> M;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     M[{0,0}]=2;
    M[{0,1}]=1;
    M[{0,2}]=0;
    M[{1,0}]=2;
    M[{1,1}]=1;
    M[{1,2}]=1;
    M[{2,0}]=1;
    M[{2,1}]=2;
    M[{2,2}]=1;
    for(int q=0; q<20; q++)
    {
        int n;
        string s;
        cin>>n>>s;
        bool dp[3][n+1][n+1];
        memset(dp,false,sizeof(dp));
        for(int i=0; i<n; i++)
        {
            int x=s[i]-'0';
            dp[x][i][i]=true;
        }
        for(int sz=2; sz<=n; sz++)
        {
            for(int l=0; l<n&&l+sz<=n; l++)
            {
                int r=l+sz-1;

                for(int k=l; k<r; k++)
                {
                    dp[0][l][r]|=dp[0][l][k]&dp[2][k+1][r];
                    dp[2][l][r]|=dp[0][l][k]&dp[0][k+1][r];
                    dp[1][l][r]|=dp[0][l][k]&dp[1][k+1][r];
                    dp[2][l][r]|=dp[1][l][k]&dp[0][k+1][r];
                    dp[1][l][r]|=dp[1][l][k]&dp[1][k+1][r];
                    dp[1][l][r]|=dp[1][l][k]&dp[2][k+1][r];
                    dp[1][l][r]|=dp[2][l][k]&dp[0][k+1][r];
                    dp[2][l][r]|=dp[2][l][k]&dp[1][k+1][r];
                    dp[1][l][r]|=dp[2][l][k]&dp[2][k+1][r];
                }

            }

        }
        if(dp[0][0][n-1])
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}
