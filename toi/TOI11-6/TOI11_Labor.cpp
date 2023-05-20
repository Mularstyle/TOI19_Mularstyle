#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    vector<long long> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    long long l=0,r=1e13;
    while(l<r)
    {
        long long mid=l+(r-l)/2;
        long long sum=0;
        for(int i=0; i<n; i++)sum+=mid/v[i];
        if(sum>=m)
            r=mid;
        else
            l=mid+1;
    }
    cout<<l;
}
