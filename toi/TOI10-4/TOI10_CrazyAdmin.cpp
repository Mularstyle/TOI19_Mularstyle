#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,x,mac=0;
    cin>>k>>n;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        vec.push_back(x);
        mac=max(mac,x);
    }
    if(n<k)
    {
        cout<<mac;
        return 0;
    }
    int l=0,r=INT_MAX;
    while(l<r)
    {
        int mid=(l+r)/2;
        int sum=0;
        int cnt=1;
        //cout<<l<<" "<<r<<endl;
        for(int i=0;i<n;i++)
        {
            if(sum+vec[i]>mid)
            {
                sum=0;
                cnt++;
            }
            sum+=vec[i];
        }
        if(cnt>k)
            l=mid+1;
        else
            r=mid;
    }
        cout<<l;

}
