#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7+3;
vector<int> prime;
bool is_prime[N];
void seive(){

	for(int i = 2; i<N; i++)
	{
		is_prime[i] = 1;
	}

	for(int i = 2; i<N; i++)
	{
		if(is_prime[i])
		{
			for(int j = i+i; j<N; j+=i)
			{
				is_prime[j] = 0;
			}
		}
	}
	for(int i = 2; i<N; i++)
	{
		if(is_prime[i]) prime.push_back(i);
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	seive(); 
	int t; cin >> t;
	int cs = 0;
	while(t--)
	{
		int n; cin >> n;
		int cnt = 0;
		for(int i = 0; i<prime.size() && prime[i] <= n; i++)
		{
			if(n-prime[i] >= prime[i] && is_prime[n-prime[i]]) {
				cnt++;
			}

		}	
		cout << "Case " << ++cs << ": " << cnt << endl;
	}
}	