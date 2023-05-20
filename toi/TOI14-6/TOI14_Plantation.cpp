#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,d;
        cin>>n>>r>>d;
        ll mxd=d+r+r;
        pair<ll,ll> ar[n];
        for(int i=0;i<n;i++)
            cin>>ar[i].f>>ar[i].s;
        sort(ar,ar+n);
        bool ch=true;
        for(int i=0;i<n-1&&ch;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ll dx=ar[j].f-ar[i].f;
                ll dy=ar[j].s-ar[i].s;
                if(dx>mxd||dy>mxd)
                    break;
                if(dx*dx+dy*dy<mxd*mxd)
                {
                    ch=false;
                    break;
                }
            }
        }
        if(ch)
            cout<<"Y\n";
        else
            cout<<"N\n";
    }

}
