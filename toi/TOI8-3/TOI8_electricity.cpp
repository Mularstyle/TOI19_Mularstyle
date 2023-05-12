#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int cost[n];
    int dp[n];
    for(int i=0;i<n;i++){
        cin>>cost[i];
        dp[i]=INT_MAX;
    }
    deque<pair<int,int>> q;
    dp[0]=cost[0];
    q.push_back({dp[0],0});
    for(int i=1;i<n;i++)
    {
        if(!q.empty()&&i-q.front().s>k)
            q.pop_front();

        dp[i]=cost[i]+q.front().f;

        while(!q.empty()&&q.back().f>dp[i])
            q.pop_back();
        q.push_back({dp[i],i});
    }
    cout<<dp[n-1];

}
