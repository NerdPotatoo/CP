#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
const int N = 1e5+9, inf = 1e9+9;
int a[N];
int t[N*4], lazy[N*4];
void push(int n, int b, int e)
{
	if(lazy[n] == -1) return;
	t[n] = lazy[n];
	if(b!=e)
	{
		lazy[lc] = lazy[n];
		lazy[rc] = lazy[n];
	}
	lazy[n] = -1;
}
void build(int n, int b, int e)
{
	lazy[n] = -1;
	if(b == e)
	{
		t[n] = a[b];
		return;
	}
	build(lc,b,mid);
	build(rc,mid+1,e);
	t[n] = min(t[lc],t[rc]);
}
void upd(int n, int b, int e, int i, int j, int v)
{
	push(n,b,e);
	if(b > j || e < i) return;
	if(b >= i && e <= j)
	{
		lazy[n] = v;
		push(n,b,e);
		return;
	}
	upd(lc,b,mid,i,j,v);
	upd(rc,mid+1,e,i,j,v);
	t[n] = min(t[lc],t[rc]);
}
int query(int n, int b, int e, int i , int j)
{
	push(n,b,e);
	if(b > j || e < i) return inf;
	if(b >= i && e <= j)
	{
		return t[n];
	}
	return min(query(lc,b,mid,i,j),query(rc,mid+1,e,i,j));
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q; cin >> n >> q;
	build(1,1,n);
	while(q--)
	{
		int ty; cin >> ty;
		if(ty == 1)
		{
			int l, r, v; cin >> l >> r >> v;
			l++;
			upd(1,1,n,l,r,v);
		}
		else{
			int l, r; cin >> l >> r;
			l++;
			cout << query(1,1,n,l,r) << endl;
		}
	}
}	