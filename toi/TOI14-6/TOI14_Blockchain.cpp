#include<bits/stdc++.h>
using namespace std;

int n,q;
map<vector<pair<int,int>>,int> M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        vector<pair<int,int>> v;
        int m;
        cin>> m;

        for(int j=0; j<m-1; j++)
        {
            int a,b;
            cin>> a >> b;
            v.push_back({a,b});
            v.push_back({b,a});
        }
        sort(v.begin(), v.end());
        if(M[v])
            M[v]++;
        else
            M[v] = 1;
    }
    while(q--)
    {
        vector<pair<int,int>> v;
        int m;
        cin>> m;

        for(int j=1; j<m; j++)
        {
            int a,b;
            cin>> a >> b;
            v.push_back({a,b});
            v.push_back({b,a});
        }
        sort(v.begin(), v.end());
        cout<< M[v] << "\n";
    }
}
