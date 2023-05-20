#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
ll ar[100005];

bool check(ll mid)
{
    int cnt=0;
    ll sum=0;
    priority_queue<ll,vector<ll>,greater<ll>> Q;
    for(int i=0;i<n;i++)
    {

        while(Q.size()>=k)
        {
            sum-=Q.top();
            Q.pop();
        }
         Q.push(ar[i]);
        sum+=ar[i];
        if(sum>=mid&&Q.size()==k)
        {
            sum=0;
            while(!Q.empty())
            {
                Q.pop();
            }
            cnt++;
        }
    }
    return cnt>=m;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ll l=0,r=LONG_MAX;
    while(l<r)
    {
        ll mid=l+(r-l)/2;
        if(!check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l-1;

}
