#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<char>> V(50005,vector<char>(80,'o'));
    int maxr=0;
    int n;
    cin>>n;
    int p,q,r;
    for(int i=0;i<n;i++)
    {
        cin>>p>>q>>r;
        p--;
        q--;
        maxr=max(maxr,p);
        for(int j=q;j<q+r&&j<70;j++)
            V[p][j]='x';

    }

    for(int i=0;i<=maxr;i++)
    {
        for(int j=0;j<70;j++)
        {
            cout<<V[i][j];
        }
        cout<<"\n";
    }


}
