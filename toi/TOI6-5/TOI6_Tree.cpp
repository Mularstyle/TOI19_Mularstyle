#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int q=0;q<5;q++)
    {
        int n,u,v;
        cin>>n;
        set<int> V[n+1],G[n+1];
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            V[u].insert(v);
            V[v].insert(u);
        }
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            G[u].insert(v);
            G[v].insert(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(V[i]!=G[i])
            {
                cout<<"N";
                goto flag;
            }
        }
        cout<<"Y";

        flag:;
    }
}
