#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    ll sum=0;
    priority_queue<int> a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push(x);
    }
    for(int j=0;j<n;j++)
    {
        cin>>x;
        b.push(x);
    }
    while(!a.empty())
    {
        sum+=abs(a.top()-b.top());
        a.pop();
        b.pop();
    }
    cout<<sum;
}
