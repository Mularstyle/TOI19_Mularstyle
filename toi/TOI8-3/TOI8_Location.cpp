#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M,N,K;
    cin>>M>>N>>K;
    int maxx=0;
    int arr[M+1][N+1];

    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>arr[i][j];
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    for(int i=K; i<=M; i++)
    {
        for(int j=K; j<=N; j++)
        {
            int sum=0;
            sum+=arr[i][j]-arr[i-K][j]-arr[i][j-K]+arr[i-K][j-K];
            if(sum>maxx)
                maxx=sum;
        }
    }
    cout<<maxx;
}
