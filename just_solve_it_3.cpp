#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+7, M = 1e6;
int cnt[N], mul[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i<=n; i++)
	{
		int x; cin >> x;
		cnt[x]++;
	}


	for(int i = 1; i<N; i++)
	{
		for(int j = i; j<N; j+=i)
		{
			mul[i] += cnt[j];
		}
	}
	for(int i = 1; i<= M; i++)
	{
		cout << mul[i] << " ";
	}
	cout << '\n';
}
