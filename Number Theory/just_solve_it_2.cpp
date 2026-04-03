#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mul(ll a, ll b, ll mod)
{
	return __int128(a) * b % mod; 
}
ll power(ll a, ll b, ll mod)
{
	ll ans = 1 % mod;
	while(b)
	{
		if(b&1) ans = mul(ans,a,mod);
		a = mul(a,a,mod);
		b>>=1;
	}
	return ans;
}
ll inv(ll a, ll mod){
	return power(a, mod-2, mod);
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a, b, mod;
	cin >> a >> b >> mod;
	cout << power(a,b,mod) << '\n';
	cout << mul(a,b,mod) << '\n';
	cout << mul(a,inv(b,mod),mod) << '\n';
}	