#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 500005
int N,Q;
int start,money;
vector<ll> cost(MX,0),point(MX,0);
bool check(int m)
{
    if(cost[m]-cost[start]<money)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    int x;
    for(int i=1;i<=N;i++)
    {
        cin>>x;
        cost[i]=cost[i-1];
        point[i]=point[i-1];
        if(x>0)
            point[i]+=x;
        else
            cost[i]-=x;
    }
    for(int i=0;i<Q;i++)
    {
        cin>>start>>money;
        int l=start+1,r=N;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(check(m))
                l=m+1;
            else
                r=m;
        }
        //while(!check(l))l--;
        cout<<point[l]-point[start]<<"\n";
    }
}

