
#include<bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,k,x;
    cin>>n>>k;
    vector<long long> vec;
    long long l=0,r=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        r=min(r,x);
        vec.push_back(x);
    }
    r*=k;


    while(l<r)
    {
        long mid=(l+r)/2;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=mid/vec[i];
        }
        if(sum<k)
            l=mid+1;
        else
            r=mid;
    }
    cout<<l;
}
