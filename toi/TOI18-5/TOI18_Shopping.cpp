#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 500005
ll p[MX],c[MX];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    ll x,mo,st;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        p[i]=p[i-1];
        c[i]=c[i-1];
        if(x>=0)
            p[i]+=x;
        else
            c[i]-=x;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>st>>mo;
        auto it=lower_bound(c+st+1,c+n,c[st]+mo)-c;
        cout<<p[it]-p[st]<<"\n";
    }

}
