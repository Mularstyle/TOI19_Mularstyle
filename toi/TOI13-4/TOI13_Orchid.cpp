
#include<bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    vector<int> vec;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(i==0)
            vec.push_back(x);
        else if (x<vec[0])
            vec[0]=x;
        else if(x>=vec.back())
        {
            vec.push_back(x);
        }
        else{
            int l=0,r=vec.size()-1;
            int pos=0;
            while(l<r)
            {
                int m=l+(r-l)/2;


                if(vec[m]<=x)
                    l=m+1;
                else
                    r=m;
            }
            vec[pos]=x;
        }
    }
    cout<<n-vec.size();
}
