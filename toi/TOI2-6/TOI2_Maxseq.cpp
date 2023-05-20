#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n;
    vector<int> vec(n+1,0),sum(n+1,0);
    cin>>vec[1];
    sum[1]=vec[1];
    int mac=INT_MIN,pos=1;
    for(int i=2;i<=n;i++)
    {
        cin>>vec[i];
        if(sum[i-1]>0)
        {
            sum[i]=sum[i-1]+vec[i];
        }
        else
        {
            sum[i]=vec[i];
        }
        if(sum[i]>mac)
        {
            mac=sum[i];
            pos=i;
        }

    }
    if(mac<=0)
        cout<<"Empty sequence";
    else
    {
        stack<int> Q;
        int kk=mac;
        for(int i=pos;i>=1&&mac!=0;i--)
        {
            Q.push(vec[i]);
            mac-=vec[i];
        }
        while(!Q.empty())
        {
            cout<<Q.top()<<" ";
            Q.pop();
        }
        cout<<"\n"<<kk;
    }
}
