
#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>m>>n;
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n-1;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
        {
            if(s[i][j]!=s[i+1][j])
            {
                cnt++;
            }
            if(cnt>2)
            {
                cout<<s[i];
                return 0;
            }
        }
    }
    cout<<s[n-1];
}
