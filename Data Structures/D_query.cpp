#include<bits/stdc++.h>
#define ll long long
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;

const int N = 30005, QQ = 2e5+9;
int t[N*4];
void build(int n, int b, int e)
{
	if(b==e)
	{
		t[n] = 0;
		return;
	}
	build(lc,b,mid);
	build(rc,mid+1,e);
	t[n] = t[lc] + t[rc];
}

void upd(int n, int b, int e, int i, int v)
{
	if(b > i || e < i) return;
	if(b == i && e == i)
	{
		t[n] += v;
		return;
	}
	upd(lc,b,mid,i,v);
	upd(rc,mid+1,e,i,v);
	t[n] = t[lc] + t[rc];
}
int query(int n, int b, int e, int i , int j)
{
	if(b > j || e < i) return 0;
	if(b>=i && e<=j)
	{
		return t[n];
	}
	return query(lc, b, mid, i, j) + query(rc, mid+1, e, i, j);
}
int a[N], ans[QQ];
vector<pair<int,int>> Q[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(1,1,n);
	int q; cin >> q;
	for(int i = 1; i <= q; i++)
	{
		int l, r; cin >> l >> r;
		Q[r].push_back({l,i});
	}

	map<int,int> last_pos;
	for(int r = 1; r <= n; r++)
	{
		if(last_pos.find(a[r]) != last_pos.end())
		{
			upd(1,1,n,last_pos[a[r]],-1);
		}
		last_pos[a[r]] = r;
		upd(1,1,n,r,1);
		for(auto [l,i]:Q[r])
		{
			ans[i] = query(1,1,n,l,r);
		}
	}

	for(int i = 1; i <= q; i++)
	{
		cout << ans[i] << '\n';
	}
}	 