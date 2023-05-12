#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,Q;
    cin>>n>>Q;
    vector<int> num(n),inc(n,1),dec(n,1);
    for(int i=0;i<n;i++)
        cin>>num[i];

    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        if(i==0)vec.push_back(num[i]);
        else if(vec.back()<num[i])
        {
            vec.push_back(num[i]);
            inc[i]=vec.size();
        }
        else{
        int pos=lower_bound(vec.begin(),vec.end(),num[i])-vec.begin();
        vec[pos]=num[i];
        inc[i]=pos+1;
        }
    }
    vec.clear();
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)vec.push_back(num[i]);
        else if(vec.back()<num[i])
        {
            vec.push_back(num[i]);
            dec[i]=vec.size();
        }
        else{
        int pos=lower_bound(vec.begin(),vec.end(),num[i])-vec.begin();
        vec[pos]=num[i];
        dec[i]=pos+1;
        }
    }
    int pos;
    for(int q=0;q<Q;q++)
    {
        cin>>pos;
        cout<<min(inc[pos],dec[pos])-1<<"\n";
    }
}
