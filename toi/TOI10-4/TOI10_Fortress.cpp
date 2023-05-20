
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 20,x,y;
    while(t--)
    {

        cin >> x >> y;
        int a = (x>>1), b = (y<<1);
        if(a < y || b < a) cout << "0\n";
        else cout << b - a + 1 << "\n";
    }
    return 0;
}
