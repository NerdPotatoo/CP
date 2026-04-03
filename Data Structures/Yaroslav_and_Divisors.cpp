#include<bits/stdc++.h>
#define ll long long
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;

const int N = 2e5 + 9;
int t[N * 4];
void build(int n, int b, int e)
{
	if(b == e)
	{
		t[n] = 0;
		return;
	}
	build(lc, b, mid);
	build(rc, mid+1, e);
	t[n] = t[lc] + t[rc];
}
void upd(int n, int b, int e, int i, int v)
{
	if(b > i || e < i) return;
	if(b == e && i == b)
	{
		t[n] += v;
		return;
	}
	upd(lc, b, mid, i, v);
	upd(rc, mid+1, e, i, v);
	t[n] = t[lc] + t[rc];
}
ll query(int n, int b, int e, int i, int j)
{
	if(b > j || e < i) return 0;
	if(b >= i && e <= j)
	{
		return t[n];
	}
	return query(lc, b, mid, i, j) + query(rc, mid+1, e, i, j);
}

int pos[N];
ll ans[N];
vector<pair<int,int>> Q[N];
vector<int> pairs[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q; cin >> n >> q;
	// map<int,int> pos;
	for(int i = 1; i<=n; i++)
	{
		int x ; cin >> x;
		pos[x] = i;
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = i; j<=n; j+=i)
		{
			int l = min(pos[i],pos[j]);
			int r = max(pos[i],pos[j]);
			pairs[r].push_back(l);
		}
	}

	for(int i = 1; i <= q; i++)
	{
		int l, r; cin >> l >> r;
		Q[r].push_back({l,i});
	}
	build(1,1,n);
	for(int r = 1; r <= n; r++)
	{
		for(auto l:pairs[r])
		{
			upd(1, 1, n, l, 1);
		}
		for(auto [l,i]: Q[r])
		{
			ll sum = query(1, 1, n, l, r);
			ans[i] = sum;
		}
	}


	for(int i = 1; i <= q; i++)
	{
		cout << ans[i] << '\n';
	}
}	