#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		int n, x, sum = 0; cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> x;
			while(x) {
				sum += x % 10;
				x /= 10;
			}
		}	
		if(sum % 3 == 0) {
			cout << "Yes" << '\n';
		}
		else {
			cout << "No" << '\n';
		}
		// cout << sum << endl;
	}
	


}	