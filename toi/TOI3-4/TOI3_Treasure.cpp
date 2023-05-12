#include<bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double x=0,y=0;
    double kn;
    string K;
    cin>>K;
    while(K[0]!='*')
    {
        double kx,ky;
        int n=K.length();
        double C=stod(K);
        for(int i=0; i<n; i++)
        {
            if(K[i]=='N'&&K[i+1]=='\0')
            {
                y+=C;
                break;
            }
            else if(K[i]=='N'&&K[i+1]=='E')
            {
                x+= sqrt((C*C)/2);
                y+= sqrt((C*C)/2);
                break;
            }
            else if(K[i]=='E'&&K[i+1]=='\0')
            {
                x+=C;
                break;
            }
            else if(K[i]=='S'&&K[i+1]=='E')
            {
                x+= sqrt((C*C)/2);
                y-= sqrt((C*C)/2);
                break;
            }
            else if(K[i]=='S'&&K[i+1]=='\0')
            {
                y-=C;
                break;
            }
            else if(K[i]=='S'&&K[i+1]=='W')
            {
                x-= sqrt((C*C)/2);
                y-= sqrt((C*C)/2);
                break;
            }
            else if(K[i]=='W'&&K[i+1]=='\0')
            {
                x-=C;
                break;
            }
            else if(K[i]=='N'&&K[i+1]=='W')
            {
                x-= sqrt((C*C)/2);
                y+= sqrt((C*C)/2);
                break;
            }
        }
        cin>>K;
    }
    double D=sqrt((x*x)+(y*y));
    printf("%.3f %.3f\n",x,y);
    printf("%.3f",D);
}
