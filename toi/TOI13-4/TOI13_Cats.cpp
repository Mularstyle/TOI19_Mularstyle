#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> cat(n);
    for(int i=0;i<n;i++)
        cin>>cat[i];

    int l=0,r=INT_MAX;
    while(l<r)
    {
        vector<int> temp;
        int m=l+(r-l)/2;
        bool ch=true;

        for(int i=0;i<n;i++)
        {
            if(cat[i]<=m)continue;
            temp.push_back(cat[i]);
        }
   // cout<<temp.size()<<"\n";

        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]!=temp[i+1]){
                ch=false;
                break;
            }
            else
            {
                i++;
            }
        }

        if(!ch)
            l=m+1;
        else
            r=m;
      //  cout<<l<<" "<<r<<"\n";

    }
    cout<<l;
}
