#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int kn,wn;
    cin>>wn>>kn;
    char C[wn+1],F[wn+1],K[kn+1];
    cin>>C>>F>>K;
    int c,f,k;
    for(int i=0;i<kn;i++)
    {
        int mx,mn,md;
        int change;
        for(int j=0;j<wn;j++)
        {
            c=C[j];
            f=F[j];
            k=K[i];
            if( c<=f && f<=k )
                K[i]=f;
            if( k<=f && f<=c )
                K[i]=f;
            else if(f<=c &&  c<= k)
               K[i]=c;
            else if(k<=c && c<=f )
                K[i] = c;
        }
    }
    cout<<K;
}
