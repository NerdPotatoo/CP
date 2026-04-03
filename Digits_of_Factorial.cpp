#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 9;
double logs[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 1; i < N; i++)
	{
		logs[i] = log2(i) + logs[i-1]; 
	}
	int t, cs = 0; cin >> t;
	while(t--)
	{
		int n, b;
		cin >> n >> b;
		double ans = logs[n] / log2(b);
		ans += 1;
		cout << "Case " << ++cs << ": " << (int)(floor(ans)) << '\n';
	}
}	