#include<bits/stdc++.h>
using namespace std;
int chp[10][2]={{0,0},{1,1},{1,2},{1,3},{2,1},{2,2},{2,3},{3,1},{3,2},{3,3}};
int pch[4][4]={{0,0,0,0},{0,1,2,3},{0,4,5,6},{0,7,8,9}};
char alp[10][5]={{""},{""},{"CAB"},{"FDE"},{"IGH"},{"LJK"},{"OMN"},{"SPQR"},{"VTU"},{"ZWXY"}};
int mods[10]={0,0,3,3,3,3,3,4,3,4};
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string word;
    int n,s,m;
    cin>>n>>s>>m;
    int h[n+1],v[n+1],c[n+1];
    int kh=chp[s][1];
    int kv=chp[s][0];
    if(pch[kv][kh]!=1)
    word+=alp[s][m%mods[s]];
    for(int i=0;i<n-1;i++)
    {
        cin>>h[i]>>v[i]>>c[i];
        kh+=h[i];
        kv+=v[i];
        if(pch[kv][kh]!=1)
            word+=alp[pch[kv][kh]][c[i]%mods[pch[kv][kh]]];
        else
        {
        while(c[i]>0)
                {
                if(word.size()>0)
                    word.erase(word.end()-1);
                c[i]--;
                }
        }
    }
  if(word.size()>0)
    cout<<word;
   else
    cout<<"null";
}
