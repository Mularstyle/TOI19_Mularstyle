
#include<bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> vec;
    vec.push_back(x);
    int cnt=1;
    int i=n-1;
    while(i--)
    {
        cin>>x;
        if(x>=vec[cnt-1])
        {
            vec.push_back(x);
            cnt++;
        }
        else
        {
            int pos=upper_bound(vec.begin(),vec.end(),x)-vec.begin();
            vec[pos]=x;
        }
    }
    cout<<n-vec.size();
}
