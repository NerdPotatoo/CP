#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << i << ' ';
		}
	}
	cout << '\n';
}
