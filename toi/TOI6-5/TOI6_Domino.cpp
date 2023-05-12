#include<bits/stdc++.h>
using namespace std;
int n;
void dom(string s,int cnt)
{
    if(cnt==n)
    {
        cout<<s<<"E\n";
        return;
    }
    else if(cnt>n)
        return;
    dom(s+"--\n",cnt+1);
    dom(s+"||\n",cnt+2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    dom("",0);
}
