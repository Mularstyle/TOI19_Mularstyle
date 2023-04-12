#include<bits/stdc++.h>
using namespace std;
int dp[101];
int main()
{

    int n;
    cin>>n;
    if(n<6)
    {
        cout<<"no";
        return 0;
    }
    dp[6]=1;
    dp[9]=1;
    dp[20]=1;
    dp[0]=1;
    int ar[]={6,9,20};
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i-ar[j]>=0&&dp[i-ar[j]]==1)
            {
                dp[i]=1;
                cout<<i<<"\n";
                break;

            }
        }
    }
}
