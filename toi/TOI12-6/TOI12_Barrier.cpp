#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pl pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    ll mac=0,num=0;
    ll ar[n];
    ll dp[n+1];
    deque<ll> q;
    for(int i=0;i<n;i++)
        cin>>ar[i];
    dp[0]=0;
    for(int i=1;i<=n;i++)
        dp[i]=dp[i-1]+ar[i-1];

    if(dp[1]>mac)
    {
        mac=dp[1];
        num=1;
    }
    q.push_back({1});
    for(int i=2;i<=n;i++)
    {
        while(!q.empty()&&i-q.front()>=k)
        {
            q.pop_front();
        }
        while(!q.empty()&&dp[q.back()-1]>dp[i-1])
        {
            q.pop_back();
        }

        q.push_back(i);

        if(dp[i]-dp[q.front()-1]>mac)
        {
            mac=dp[i]-dp[q.front()-1];
            num=i-q.front()+1;
        }
        else if(dp[i]-dp[q.front()-1]==mac)
        {
            num=min(num,i-q.front()+1);
        }
    }
    cout<<mac<<"\n"<<num;

}
