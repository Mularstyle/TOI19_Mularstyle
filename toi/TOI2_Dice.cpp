#include<bits/stdc++.h>
using namespace std;

map<int,int> F,B,L,R,C,D;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> d={0,1,2,3,5,4,6};
    F[1]=4,F[2]=1,F[3]=3,F[4]=6,F[5]=5,F[6]=2;
    B[1]=2,B[2]=6,B[3]=3,B[4]=1,B[5]=5,B[6]=4;
    L[1]=5,L[2]=2,L[3]=1,L[4]=4,L[5]=6,L[6]=3;
    R[1]=3,R[2]=2,R[3]=6,R[4]=4,R[5]=1,R[6]=5;
    C[1]=1,C[2]=5,C[3]=2,C[4]=3,C[5]=4,C[6]=6;
    D[1]=1,D[2]=3,D[3]=4,D[4]=5,D[5]=2,D[6]=6;
    string s;

    for(int i=0;i<n;i++)
    {
        cin>>s;
        vector<int> t=d,tt;

        for(int j=0;j<s.length();j++)
        {
            tt=t;
            if(s[j]=='F')
            {
                for(int k=1;k<=6;k++)
                {
                    t[k]=tt[F[k]];
                }
            }
            else if(s[j]=='B')
            {
                for(int k=1;k<=6;k++)
                {
                    t[k]=tt[B[k]];
                }
            }
            else if(s[j]=='L')
            {
                for(int k=1;k<=6;k++)
                {
                    t[k]=tt[L[k]];
                }
            }
            else if(s[j]=='R')
            {
                for(int k=1;k<=6;k++)
                {
                    t[k]=tt[R[k]];
                }
            }
            else if(s[j]=='C')
            {
                for(int k=1;k<=6;k++)
                {
                    t[k]=tt[C[k]];
                }
            }
            else if(s[j]=='D')
            {
                for(int k=1;k<=6;k++)
                {
                    t[k]=tt[D[k]];
                }
            }

        }


       cout<<t[2]<<" ";
    }

}
