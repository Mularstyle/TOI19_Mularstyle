#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define pi pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,mn=LONG_MAX,cnt=0,h,ans=LONG_MAX;
    cin>>n;
    pi a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].s;
        mn=min(mn,a[i].s);
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i].f;
    }
    sort(a,a+n);
    h=a[0].f;
    for(int i=0;i<n;i++)
        cnt+=a[i].f-a[0].f;
    ans=cnt;
    for(int i=1;i<n;i++)
    {
        if(a[i].f>mn)break;
        cnt-=(a[i].f-a[i-1].f)*n;
        cnt+=a[i-1].s;
        if(cnt<ans)
        {
            h=a[i].f;
            ans=cnt;
        }
    }
    cout<<h<<" "<<ans;
}
