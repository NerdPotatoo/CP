#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
const int N = 1e5+9;
int a[N];
int t[4*N], lazy[4*N];
void push(int n, int b, int e)
{
	if(lazy[n] == 0) return;
	t[n] = max(t[n],lazy[n]);
	if(b != e)
	{
		lazy[lc] = max(lazy[lc],lazy[n]);
		lazy[rc] = max(lazy[rc],lazy[n]);
	}
	lazy[n] = 0;
}
void build(int n, int b, int e)
{
	if(b == e)
	{
		t[n] = a[b];
		return;
	}
	build(lc, b, mid);
	build(rc, mid+1, e);
	t[n] = max(t[lc],t[rc]);
}
void upd(int n, int b, int e, int i, int j, int v)
{
	push(n,b,e);
	if(b > j || e < i) return;
	if(b >= i && e <= j)
	{
		lazy[n] = max(lazy[n],v);
		return;
	}
	upd(lc,b,mid,i,j,v);
	upd(rc,mid+1,e,i,j,v);
	t[n] = max(t[lc], t[rc]);
}

int query(int n, int b, int e, int i, int j)
{
	push(n,b,e);
	if(b > j || e < i) return 0;
	if(b >= i && e <= j)
	{
		return t[n];
	}
	return max(query(lc, b, mid, i, j), query(rc, mid+1, e, i, j));
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q; cin >> n >> q;
	build(1,1,n);
	while(q--)
	{
		int ty; cin >> ty;
		if(ty == 1)
		{
			int l, r, v;
			cin >> l >> r >> v;
			++l;
			// update
			upd(1,1,n,l,r,v);
		}
		else{
			int i; cin >> i;
			++i;
			// query
			cout << query(1,1,n,i,i) << '\n';
		}
	}
}	