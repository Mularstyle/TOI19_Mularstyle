#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,cnt=0;
    cin>>n;
    string s;
    while(n--)
    {
        cin>>s;
        int l=s.length();
        bool ans=false;
        while(l--)
        {
            bool ch=true;
            for(int i=0; i<s.length()/2; i++)
            {
                if(s[i]!=s[s.length()-1-i])
                {
                    ch=false;
                    break;
                }
            }
            s+=s[0];
            s.erase(s.begin());
            if(ch)
            {
                ans=true;
                break;
            }
        }
        if(ans){
            cnt++;
         //   cout<<s<<"\n";
        }
    }
    cout<<cnt;
}

