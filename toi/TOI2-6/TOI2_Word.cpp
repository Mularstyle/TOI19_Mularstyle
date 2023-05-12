#include<bits/stdc++.h>

using namespace std;
 int N,M;
char W[10000][10000];
bool check1(string WC,int xi,int xj,int key)
{
    int len=WC.length()-1;

    if(W[xi][xj]==WC[key]&&key==len)
    {
        return true;
    }
    if(W[xi][xj]==WC[key])
    {
        return check1(WC,xi+1,xj,key+1);
    }
    return false;
}
bool check2(string WC,int xi,int xj,int key)
{
    int len=WC.length()-1;
    if(W[xi][xj]==WC[key]&&key==len)
    {
        return true;
    }
    if(W[xi][xj]==WC[key])
    {
        return check2(WC,xi-1,xj,key+1);
    }
    return false;
}
bool check3(string WC,int xi,int xj,int key)
{
    int len=WC.length()-1;
    if(W[xi][xj]==WC[key]&&key==len)
    {
        return true;
    }
    if(W[xi][xj]==WC[key])
    {
        return check3(WC,xi,xj+1,key+1);
    }
    return false;
}
bool check4(string WC,int xi,int xj,int key)
{
int len=WC.length()-1;
    if(W[xi][xj]==WC[key]&&key==len)
    {
        return true;
    }
    if(W[xi][xj]==WC[key])
    {
        return check4(WC,xi,xj-1,key+1);
    }
    return false;
}
bool check5(string WC,int xi,int xj,int key)
{
    int len=WC.length()-1;
    if(W[xi][xj]==WC[key]&&key==len)
    {
        return true;
    }
    if(W[xi][xj]==WC[key])
    {
        return check5(WC,xi+1,xj+1,key+1);
    }
    return false;
}
bool check6(string WC,int xi,int xj,int key)
{
    int len=WC.length()-1;
    if(W[xi][xj]==WC[key]&&key==len)
    {
        return true;
    }
    if(W[xi][xj]==WC[key])
    {
        return check6(WC,xi-1,xj-1,key+1);
    }
    return false;
}
bool check7(string WC,int xi,int xj,int key)
{
    int len=WC.length()-1;
    if(W[xi][xj]==WC[key]&&key==len)
    {
        return true;
    }
    if(W[xi][xj]==WC[key])
    {
        return check7(WC,xi+1,xj-1,key+1);
    }
    return false;
}
bool check8(string WC,int xi,int xj,int key)
{
    int len=WC.length()-1;
    if(W[xi][xj]==WC[key]&&key==len)
    {
        return true;
    }
    if(W[xi][xj]==WC[key])
    {
        return check8(WC,xi-1,xj+1,key+1);
    }
    return false;
}
bool MS[100000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(MS,false,sizeof(MS));
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>W[i][j];
            W[i][j]=toupper(W[i][j]);
        }
    }
    int aw;
    cin>>aw;
    string AW[aw+2];
    for(int i=0;i<aw;i++)
        {cin>>AW[i];
        }
    for(int i=0;i<aw;i++)
    {
        for(int j=0;j<AW[i].length();j++)
            {
        AW[i][j]=toupper(AW[i][j]);
        }
    }
    for(int k=0;k<aw;k++){
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
          if(W[i][j]==AW[k][0]&&MS[k]==false)
          {
              if(check1(AW[k],i,j,0) )
              {
                  cout<<i<<" "<<j<<"\n";
                  MS[k]=true;
                  break;
              }
             else if(check2(AW[k],i,j,0) )
              {
                  cout<<i<<" "<<j<<"\n";
                  MS[k]=true;
                  break;
              }
            else  if(check3(AW[k],i,j,0) )
              {
                  cout<<i<<" "<<j<<"\n";
                  MS[k]=true;
                  break;
              }
             else if(check4(AW[k],i,j,0) )
              {
                  cout<<i<<" "<<j<<"\n";
                  MS[k]=true;
                  break;
              }
             else if(check5(AW[k],i,j,0) )
              {
                  cout<<i<<" "<<j<<"\n";
                  MS[k]=true;
                  break;
              }
             else if(check6(AW[k],i,j,0) )
              {
                  cout<<i<<" "<<j<<"\n";
                  MS[k]=true;
                  break;
              }
           else   if(check7(AW[k],i,j,0) )
              {
                  cout<<i<<" "<<j<<"\n";
                  MS[k]=true;
                  break;
              }
            else  if(check8(AW[k],i,j,0) )
              {
                  cout<<i<<" "<<j<<"\n";
                  MS[k]=true;
                  break;
              }
          }
        }
    }
    }
}

