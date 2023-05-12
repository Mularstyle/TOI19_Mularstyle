#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<ll,int>
#define f first
#define s second
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    ll dp[n+1];
    int ans[q];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>dp[i];
        dp[i]+=dp[i-1];
    }
    priority_queue<pl,vector<pl>,less<pl>> Q;
    ll u;
    for(int i=0;i<q;i++)
    {
        cin>>u;
        Q.push({u,i});
    }
    for(int i=n;i>=1;i--)
    {
        while(!Q.empty()&&Q.top().f>=dp[i])
        {
            ans[Q.top().s]=i;
            Q.pop();
        }
    }
    while(!Q.empty())
    {
        ans[Q.top().s]=0;
        Q.pop();
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<"\n";
}
