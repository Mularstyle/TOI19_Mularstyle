#include<bits/stdc++.h>

using namespace std;
char op[15][4][4]
={{" _ ","| |","|_|"},
  {"   ","  |","  |"},
  {" _ "," _|","|_ "},
  {" _ "," _|"," _|"},
  {"   ","|_|","  |"},
  {" _ ","|_ "," _|"},
  {" _ ","|_ ","|_|"},
  {" _ ","  |","  |"},
  {" _ ","|_|","|_|"},
  {" _ ","|_|"," _|"}
};
long int cal(int a)
{
    string word[5];
    for(int i=0;i<3;i++)
        getline(cin,word[i]);
   long  int ans=0;
    int wj=0,wi=0;
    while(a>0)
    {
        ans*=10;
        for(int i=0;i<10;i++)///0-9
        {
            int check=1;
            for(int ia=0;ia<3;ia++)
            {
                {
                    for(int ij=0,ni=wi;ij<3;ij++,ni++)
                    {
                        if(op[i][ia][ij]!=word[ia][ni])
                        {
                            check=0;
                        }
                    }
                }
            }
            if(check)
            {
                ans+=i;
            }
        }
        wi+=4;
        a--;
    }
    //cout<<ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0);
    int n,m;
    cin>>n>>m;
    string temp;
    getline(cin,temp);
    long int a=cal(n);
   long int b=cal(m);
    cout<<a+b;
    return 0;
}

