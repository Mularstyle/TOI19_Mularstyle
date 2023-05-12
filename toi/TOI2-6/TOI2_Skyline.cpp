#include<bits/stdc++.h>

using namespace std;
int T[5000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int l,h,r;
    int mx=0;
    int mn=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>l>>h>>r;
        for(int j=l;j<r;j++)
        {
            T[j]=max(T[j],h);
        }
         mx=max(mx,r);
        mn=min(mn,l);
    }
    for(int i=mn;i<=mx;i++)
    {
        int l=i;
        int h=T[l];
        cout<<l<<" "<<h<<" ";
        int j;
        for( j=i+1;j<=mx;j++)
        {
            if(T[j]!=T[i])
            {
                break;
            }
        }
        i=j-1;
    }
}
