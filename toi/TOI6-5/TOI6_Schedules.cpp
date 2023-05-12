#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pi pair<int,int>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    int x,y,z,cnt=0;
    cin>>n>>k>>m;
    vector<bool> f(n+2,false);
    vector<pair<int,pi>> vec;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        vec.push_back({x,{1,i}});
        vec.push_back({y+1,{-1,i}});
    }
    sort(vec.begin(),vec.end());
    for(auto v : vec)
    {
        x=v.f,y=v.s.f,z=v.s.s;
        if(y==1&&cnt<k)
        {
            f[z]=1;
            cnt++;
        }
        else if(y==-1&&f[z])
        {
            cnt--;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        if(f[x])
            cout<<"Y ";
        else
            cout<<"N ";
    }
}
