#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n=1000,c,cnt=0;
    int ansi,ansb;
    double mn=INT_MAX,p,s;
    cin>>c;
    int b=100000+c;
    while(n<=15000){
        for(int i=74;i<=144;i++)
        {
            s=((100-(0.8569*exp(0.09*(i-100))))*n/100);
            p=s*i-b;
            if(p>0&&p<mn){
                mn=p;
                ansb=n;
                ansi=i;
            }
        }
    cnt++;
    n+=500;
    b=n*(100-cnt)+c;
    }
    printf("%d\n%d\n%.2lf",ansb,ansi,mn);
}
