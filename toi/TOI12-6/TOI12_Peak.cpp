#include<bits/stdc++.h>
using namespace std;
void scan(int &n){
    bool neg = 0; char c;
    n = 0; c = getchar();
    if(c == '-') neg = 1, c = getchar();
    for(; (c > 47 && c < 58); c = getchar())
        n = n * 10 + c - 48;
    if(neg) n = -n;
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,x;
    scan(n);scan(k);
    vector<int> mou,a(n);
    for(int i=0;i<n;i++)
        scan(a[i]);
    for(int i=0;i<n;i++)
    {
        if((i-1<0||a[i]>a[i-1])&&(i+1>=n||a[i]>a[i+1]))
            mou.push_back(a[i]);
    }
    sort(mou.begin(),mou.end());
    mou.resize(unique(mou.begin(),mou.end())-mou.begin());
    x=mou.size();
    if(x==0)
    {
        cout<<"-1";
    }
    else if(x<k)
    {
        for(int i=0;i<x;i++)
            cout<<mou[i]<<"\n";
    }
    else
    {
        reverse(mou.begin(),mou.end());
        for(int i=0;i<k;i++)
            cout<<mou[i]<<"\n";
    }

}
