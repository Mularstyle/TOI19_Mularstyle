#include<bits/stdc++.h>
using namespace std;
vector<int> G[64],L[64][64];
vector<bool> vis(64,false);
int main()
{
    int N;
    cin>>N;
    int u,v,w;
    char a,b;
    for(int i=0;i<N;i++)
    {
        cin>>a>>b>>w;
        u=(int)a-'X';
        v=(int)b-'X';
        G[u].push_back(v);
        G[v].push_back(u);
        L[u][v].push_back(w);
        L[v][u]. push_back(w);
    }
    stack<int> S;
    queue<int> Q;
    vis[0]=true;
    S.push(0);
    while(!S.empty())
    {
        u=S.top();
        S.pop();
        Q.push(u);
        for(auto &it:G[u])
        {
            if(vis[it])continue;
            S.push(it);
            vis[it]=true;
        }
    }
    double cost=0,med;
    if(vis[1]==false)
    {
        cout<<"broken";
        return 0;
    }
    u=0;
    Q.pop();
    while(!Q.empty())
    {
        v=Q.front();
        Q.pop();
        sort(L[u][v].begin(),L[u][v].end());
        int len=L[u][v].size();
        if(len%2==0)
            med=((L[u][v][len/2]+L[u][v][len/2-1])/2.0);
        else
            med=(L[u][v][len/2]);
        a=u+'X';
        b=v+'X';
        printf("%c %c %.1f\n",a,b,med);
        cost+=med;
        u=v;
    }
        printf("%.1f\n",cost);
}
