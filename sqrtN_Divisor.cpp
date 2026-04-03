#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> div;
	int n; cin >> n;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			div.push_back(i);
			if (i != n/i) div.push_back(n/i);
		}
	}	
	sort(div.begin(), div.end());

	for (int x : div) {
		cout << x << ' ';
	} cout << endl;
}