#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    long long sum=0;
    while(n>0)
    {
        if(n>=9){n-=15;sum+=3000;}
        else if(n>=4){n-=5;sum+=1500;}
        else if(n>=2){n-=2;sum+=800;}
        else if(n>=1){n-=1;sum+=500;}
    }
    cout<<sum;
}
