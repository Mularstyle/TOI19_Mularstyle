#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    deque<int> v;
    for(int i=1;i<=n;i++)
        v.push_back(i);

    while(v.size())
    {
        int k=v.size();
        for(int i=0;i<m-1;i++)
        {
            v.push_back(v.front());
            v.pop_front();
        }
        cout<<v.front()<<" ";
        v.pop_front();
    }
}
