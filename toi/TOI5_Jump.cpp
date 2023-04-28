#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    int mac=0;
    for(int i=0;i<n;i++)
    {
        int pos=upper_bound(vec.begin()+i,vec.end(),vec[i]+k)-vec.begin();
        mac=max(mac,pos-i);
    }
    cout<<mac-1;
}
