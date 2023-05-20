
#include <bits/stdc++.h>
using namespace std;
bool isp[10000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n,cnt=0,ans;
	cin >> n;
	for(int i = 2;i<=10000001;i++) {
		if(!isp[i]) {
			for(int j = i;j<=10000001;j+=i) isp[j] = true;
			cnt++;
			if(cnt==n) {ans = i;break;}
		}
	}
	cout << ans;
}
