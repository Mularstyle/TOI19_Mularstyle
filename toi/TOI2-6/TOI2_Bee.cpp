
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a(25,0),b(25,1);
    int x;
    for(int i=1;i<=24;i++)
    {
        a[i]=b[i-1];
        b[i]=a[i-1]+b[i-1]+1;

    }
    cin>>x;
    while(x!=-1)
    {
        cout<<b[x]<<" "<<a[x]+b[x]+1<<"\n";
        cin>>x;
    }

}
