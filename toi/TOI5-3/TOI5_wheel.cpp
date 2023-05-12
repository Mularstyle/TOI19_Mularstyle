
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    deque<int> e1(9),e2(9),e3(9);
    string src,key,ans ;
    cin>>src>>key;
    e1[0]=src[0]-'0',e2[0]=src[1]-'0',e3[0]=src[2]-'0';
    for(int i=1;i<9;i++)
    {
    if(e1[i-1]==9)e1[i]=1;
    else e1[i]=e1[i-1]+1;
    if(e2[i-1]==9)e2[i]=1;
    else e2[i]=e2[i-1]+1;
    if(e3[i-1]==9)e3[i]=1;
    else e3[i]=e3[i-1]+1;
    }
    for(int i=0;i<key.length();i++)
    {
    ans+=(e3[e2[e1[key[i]-'0'-1]-1]-1]+'0');
    int s1=src[0]-'0',s3=src[2]-'0';
    //cout<<s1<<" "<<s3<<"\n";
    while(s1--){e1.push_back(e1[0]);e1.pop_front();}
    while(s3--){e3.push_back(e3[0]);e3.pop_front();}
    e2.push_front(e2[8]);e2.pop_back();
    }
    cout<<ans;

}
