#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string org,swi;
    cin>>n>>org;
    swi=org+org;
    int cnt;
    for( cnt=1; cnt<=n; cnt++)
    {
        if(n%cnt==0&&swi.substr(cnt,n)==org)
        {
            cout<<cnt;
            return 0;
        }
    }
    return 0;
}
