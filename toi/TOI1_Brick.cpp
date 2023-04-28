
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    char b[n+1][m+1];
    for(int i=0;i<n;i++)
        cin>>b[i];
    int r[m];
    int mic[m];

    for(int i=0;i<m;i++){
        cin>>r[i];
        mic[i]=n;
    }

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {

            if(b[i][j]=='O')
            {
                mic[j]=min(i,mic[j]);
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int i=mic[j]-1;i>=mic[j]-r[j]&&i>=0;i--)
        {
            b[i][j]='#';
        }
    }

    for(int i=0;i<n;i++)
    {

        cout<<b[i]<<"\n";
    }



}
