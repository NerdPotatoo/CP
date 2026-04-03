#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool is_prime(int n)
{
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0) return false;
	}
	return true;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	if(is_prime(n))
	{
		cout << 1 << '\n';
	}
	else if(n&1)
	{
		if(is_prime(n-2))
		{
			cout << 2 << '\n';
		}
		else cout << 3 << '\n';
	}
	else {
		cout << 2 << '\n';
	}
}	