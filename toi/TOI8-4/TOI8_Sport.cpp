#include<bits/stdc++.h>
using namespace std;

int k;
vector<string> ans;

void sol(int a,int b,string s)
{
    if(a>=k||b>=k)
    {
        ans.push_back({s});
        return;
    }
    sol(a+1,b,s+"W ");
    sol(a,b+1,s+"L ");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>k>>a>>b;
    sol(a,b,"");
    for(auto v : ans)
        cout<<v<<"\n";
}
