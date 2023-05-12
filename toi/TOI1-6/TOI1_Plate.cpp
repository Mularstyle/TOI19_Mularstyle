#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    map<int,int> M;
    int c,s;
    for(int i=0;i<m;i++)
    {
        cin>>c>>s;
        M[s]=c;
    }
    vector<int> room[n+1];
    queue<int> Q;

    char k;
    while(k!='X')
    {
        cin>>k;
        if(k=='E')
        {
            cin>>s;
            c=M[s];

                if(room[c].size()==0)
                    Q.push(c);
            room[c].push_back(s);
        }
        else if(k=='D')
        {
            c=Q.front();
            s=room[c][0];
            room[c].erase(room[c].begin());
            if(room[c].empty())
                Q.pop();
            cout<<s<<"\n";
        }
    }
    cout<<"0";
    return 0;
}
