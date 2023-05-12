#include<bits/stdc++.h>
using namespace std;
#define MX 15005
#define f first
#define s second
#define pi pair<int,int>
vector<pair<int,int>> node(MX);

bool vis[MX];
int cal(int i,int j)
{
    return abs(node[i].f-node[j].f)+abs(node[i].s-node[j].s);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> path(n);
    for(int i=0;i<n;i++)
    {
        cin>>node[i].f>>node[i].s;
    }
    for(int i=0;i<n;i++)
    {
        path[i]=INT_MAX;
    }
    long long sum=0;
    for(int i=0;i<n-1;i++)
    {
        int mn=INT_MAX;
        int pos=-1;

        for(int j=i+1;j<n;j++)
        {
            int dis=cal(i,j);
            path[j]=min(path[j],dis);
            if(path[j]<mn)
            {
                mn=path[j];
                pos=j;
            }
        }

        swap(path[i+1],path[pos]);
        swap(node[i+1],node[pos]);

    }



    sort(path.begin(),path.end());
    for(int i=0;i<n-k;i++)
    {
        sum+=path[i];
    }
    cout<<sum;
}
