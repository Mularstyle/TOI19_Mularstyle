#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 100005
int N,M,K;
vector<ll> nood(MX);
bool check(ll m)
{
    int cnt=0;
    ll sum=0;
    priority_queue<ll,vector<ll>,greater<ll>> Q;
    for(int i=0;i<N;i++)
    {
        sum+=nood[i];
        Q.push({nood[i]});
        while(Q.size()>K)
        {
         sum-=Q.top();
         Q.pop();
        }
        if(sum>=m&&Q.size()==K)
        {
            sum=0;
            cnt++;
            while(!Q.empty())Q.pop();
        }

    }
    return cnt>=M;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    for(int i=0;i<N;i++)
        cin>>nood[i];

    ll l=0,r=LONG_MAX;

    while(l<r)
    {
        ll m=l+(r-l)/2;
        if(check(m))l=m+1;
        else r=m;
    }
    cout<<l-1;

}
