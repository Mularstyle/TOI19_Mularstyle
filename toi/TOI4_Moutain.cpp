#include<bits/stdc++.h>
using namespace std;
int main()
{
    char M[1005][1005];
    int mxh=0;
    int mxs=0;
    memset(M,'.',sizeof(M));
    int q;
    cin>>q;
    queue<int> QH,QHH;
    queue<int> QS,QSS;
    int S,H;
    for(int iq=0;iq<q;iq++)
    {
        cin>>S>>H;
        mxs=max(mxs,S+H*2-1);
        mxh=max(mxh,H);
        int j=1;
        QH.push(H);
        QS.push(S);
        QHH.push(H);
        QSS.push(S);
    }
    for(int iq=0;iq<q;iq++)
    {
            int H=QH.front();
            int S=QS.front();
            QH.pop();
            QS.pop();
            int i=mxh;
            for(int j=S;j<=H*2+S-1;j++)
        {
            if(j<S+H)
            {
                if(M[i][j]=='\\' )
                    M[i][j]='v';
                else
                    M[i][j]='/';
                i--;
            }
            else
            {
                i++;
                if(M[i][j]=='/' )
                    M[i][j]='v';
                else
                    M[i][j]='\\';
            }
        }
    }
    for(int iq=0;iq<q;iq++)
    {
         int H=QHH.front();
            int S=QSS.front();
            QHH.pop();
            QSS.pop();
            int ss=S+1;
        int ssm=S+2*H-2;
        for(int ii=mxh;ii>mxh-H+1;ii--)
        {
            for(int jj=ss;jj<=ssm;jj++)
                M[ii][jj]='X';
            ss++;
            ssm--;
        }
    }
    for(int i=1;i<=mxh;i++)
    {
        for(int j=1;j<=mxs;j++)
            cout<<M[i][j];
        cout<<"\n";
    }
}
