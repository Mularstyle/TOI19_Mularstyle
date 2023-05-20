#include<bits/stdc++.h>
using namespace std;
int n;
void sol(string s,int cnt)
{
    if(cnt==n)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                cout<<s<<" ";
                s[i]='1';
                cout<<s<<"\n";
                s[i]='0';

            }
        }
    }
    else
    {
        sol(s+'0',cnt+1);
        sol(s+'1',cnt+1);
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    sol("",0);

}
