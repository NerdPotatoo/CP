#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+9;
bool is_prime[N];
void sieve()
{
	is_prime[1] = 0;
	for(int i = 2; i < N; i++) is_prime[i] = 1;
	for(int i = 2; i < N; i++)
	{
		if(is_prime[i])
		{
			for(int j = i+i; j < N; j += i)
			{
				is_prime[j] = 0;
			}
		}
	}
}
bool has_zero(int x) {
	while(x) {
		if(x%10 == 0) {
			return true;
		}
		x/=10;
	}
	return false;
}

bool is_valid(int x) {
	if(!is_prime[x]) {
		return false;
	}
	if(has_zero(x)) {
		return false;
	}
	string s = to_string(x);
	int len = s.size();
	for(int i = 0; i<len; i++)
	{
		string suffix = s.substr(i);
		x = stoi(suffix);
		if(!is_prime[x]) return false;
	}
	return true;
}
bool valid[N];
int valid_pref[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve();	
	for(int i = 1; i<N; i++)
	{
		valid[i] = is_valid(i);
		
	}
	for(int i = 1; i<N; i++)
	{
		valid_pref[i] = valid_pref[i-1] + valid[i];
	}
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		cout << valid_pref[n] << endl;
	}
}
