
#include<bits/stdc++.h>
using namespace std;

int n,m;
void food(vector<int> ans,vector<int> vec,int cnt)
{
    if(cnt==n)
    {
        for(auto v:ans)
            cout<<v<<" ";
        cout<<"\n";
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(vec[i]!=0)
            {
                ans[cnt]=vec[i];
                vec[i]=0;
                food(ans,vec,cnt+1);
                vec[i]=ans[cnt];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int>  vec(n),b(n+1,0);
    for(int i=0;i<n;i++)
        vec[i]=i+1;
    int x;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        b[x]=1;
    }
    vector<int> ans(n);
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            ans[0]=i;
            vec[i-1]=0;
            food(ans,vec,1);
            vec[i-1]=i;

        }
    }


}
