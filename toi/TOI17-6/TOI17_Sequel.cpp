#include<bits/stdc++.h>
using namespace std;
#define MX 100005
long long dp[100][MX];
int a[MX];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<100;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i][max(0,j-i)]+a[j];
        }
    }

    int l,m,r;
    for(int i=0;i<q;i++)
    {
        cin>>l>>m>>r;
        int sum=0;

        if(m<100)
            cout<<dp[m][l+((r-l)/m)*m]-dp[m][max(0,l-m)]<<" ";
        else
        {

            for(int j=l;j<=r&&j<=n;j+=m)
                sum+=a[j];
            cout<<sum<<" ";
        }
    }

}
