#include<bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k,l,pos;
    cin>>n>>m>>k>>l;
    vector<int> can;
    for(int i=0;i<n;i++)
    {
        cin>>pos;
        can.push_back(pos);
       // cout<<"c";
    }

    sort(can.begin(),can.end());
    while(k--)
    {
       // cout<<"c\n";
        int cnt=0;
        vector<int> vec=can;
        bool vis[vec.size()];
        memset(vis,false,sizeof(vis));
        int stidx=0;
        for(int i=0;i<m;i++)
        {
            cin>>pos;
            int a=lower_bound(vec.begin()+stidx,vec.end(),pos-l)-vec.begin();
            int b=upper_bound(vec.begin()+stidx,vec.end(),pos+l)-vec.begin();
            stidx=b;
            for(int j=a;j<b;j++)
            {
                if(!vis[j])
                    cnt++;
                vis[j]=true;
            }
        }

    cout<<cnt<<"\n";
    }
}
