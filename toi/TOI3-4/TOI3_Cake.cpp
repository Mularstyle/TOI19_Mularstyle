#include<bits/stdc++.h>
#include<cmath>
using namespace std;
float cake[5];
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    float time[]= {8,6,4,2,1};;
    cin>>n;
    float temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
        {
            cin>>temp;
            cake[j]+=temp*time[j];
        }
    }
    float ans=ceil((cake[0]+cake[1]+cake[2]+cake[3]+cake[4])/8);
    cout<<ans;
}

