#include<bits/stdc++.h>
using namespace std;
int T[20][20];
bool check(int i,int j)
{
    int M=T[i][j];
    int Co=1;
    int c1 = (T[i-1][j]==M);//
    int c2 = (T[i][j-1]==M);
    int c3 = (T[i][j+1]==M);
    int c4 = (T[i+1][j]==M);
    Co= Co + c1 + c2 + c3 + c4;
    if(Co==3&&c1==1&&c4==1)
        return false;
    if(Co==3&&c2==1&&c3==1)
        return false;
    if(Co==3)
    {
        Co += c1*(T[i-1][j-1]==M) + c1*(T[i-1][j+1]==M)  + c1*(T[i-2][j]==M);
        Co += c2*(T[i-1][j-1]==M) + c2*(T[i+1][j-1]==M)  + c2*(T[i][j-2]==M);
        Co += c3*(T[i-1][j+1]==M) + c3*(T[i+1][j+1]==M) + c3*(T[i][j+2]==M);
        Co += c4*(T[i+1][j-1]==M) + c4*(T[i+1][j+1]==M)  +  c4*(T[i+2][j]==M);
        if(Co==3)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>T[i][j];
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(T[i][j]!=0&&check(i,j))
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
}
