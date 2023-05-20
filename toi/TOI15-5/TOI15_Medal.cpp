#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    vector<int> pro(N),sta(N);
    for(int i=0;i<N;i++)
        cin>>pro[i];
    for(int j=0;j<N;j++)
        cin>>sta[j];
    sort(pro.begin(),pro.end());
    sort(sta.begin(),sta.end(),greater<int>());
    for(int i=0;i<N;i++)
        pro[i]+=sta[i];
    ll sum=0;
    sort(pro.begin(),pro.end());
    for(int i=0;i<N-1;i++)
        sum+=abs(pro[i]-pro[i+1]);
    cout<<sum;
}
