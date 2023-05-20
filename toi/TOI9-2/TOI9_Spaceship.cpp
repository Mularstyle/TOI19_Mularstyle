#include<bits/stdc++.h>
using namespace std;
int n,m;
int mn=INT_MAX;
int q,w,e;
struct node{
    int x,y,z,a,b,c;
};
vector<node> v(505);
int cal(int i,int j)
{
    return (v[i].x-v[j].x)*(v[i].x-v[j].x)+(v[i].y-v[j].y)*(v[i].y-v[j].y)+(v[i].z-v[j].z)*(v[i].z-v[j].z);
}

void sol(int idx,int sum,vector<bool> vis,int a,int b,int c)
{
    if(a>=n&&b>=n&&c>=n)
    {
        mn=min(mn,sum);
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                sol(i,sum+cal(idx,i),vis,a+v[i].a,b+v[i].b,c+v[i].c);
                vis[i]=0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y,z,a,b,c;
    cin>>n;
    cin>>x>>y>>z;
    cin>>m;
    v[0]={x,y,z,0,0,0};
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>z>>a>>b>>c;
        v[i]={x,y,z,a,b,c};
    }
    vector<bool> vis(505,false);
    sol(0,0,vis,0,0,0);
    cout<<mn;
}
