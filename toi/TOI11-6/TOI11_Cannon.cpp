#include<bits/stdc++.h>
using namespace std;
int vec[10000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K,L;
    cin>>N>>M>>K>>L;

    //memset(vec,0,sizeof(vec));
    int x;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        vec[x]=1;
    }
    for(int i=1;i<10000005;i++)
        vec[i]+=vec[i-1];
    while(K--){
        int l=0,r=0;
        int x;
        int cnt=0;
        for(int j=0;j<M;j++)
        {
            cin>>x;
            l=max(r,x-L-1);
            r=min(10000000,x+L);
            cnt+=(vec[r]-vec[l]);
        }
        cout<<cnt<<"\n";
    }
}
