#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int o=n,e=n;
    int co=0,ce=0;
    int win,pos,x,cnt=0;
    while(1)
    {
        cin>>x;
        if(x%2==0)
        {
            if(ce>=2)
                o-=3;
            else
                o--;
            ce++;
            co=0;
        }
        else
        {
            if(co>=2)
                e-=3;
            else
                e--;
            co++;
            ce=0;
        }
        if(o<=0)
        {
            win=0;
            break;
        }
        else if(e<=0)
        {
            win=1;
            break;
        }
    }
    cout<<win<<endl<<x;
}

