#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+9;
int a[N];
struct ST{
	#define lc (n<<1)
	#define rc ((n<<1)+1)
	#define mid ((b+e)>>1)
	ll t[N*4], lazy[N*4];
	ST()
	{
		memset(t,0,sizeof t);
		memset(lazy,0,sizeof lazy);
	}
	inline void push(int n, int b, int e)
	{	
		if(lazy[n] == 0) return;
		t[n] = t[n] + lazy[n] * (e-b+1);
		if(b!=e)
		{
			lazy[lc] += lazy[n];
			lazy[rc] += lazy[n];
		}
		lazy[n] = 0;
	}
	inline ll combine(ll a, ll b)
	{
		return a+b;
	}
	inline void pull(int n)
	{
		t[n] = t[lc] + t[rc];
	}

	void build(int n, int b, int e)
	{
		lazy[n] = 0;
		if(b == e)
		{
			t[n] = a[b];
			return;
		}
		build(lc,b,mid);
		build(rc,mid+1,e);
		pull(n);
	}
	void upd(int n, int b, int e, int i, int j, int v)
	{
		push(n, b, e);
		if(i > e || j < b) return;
		if(b>=i && e<=j)
		{
			lazy[n] = v;
			push(n,b,e);
			return;
		}
		upd(lc,b,mid,i,j,v);
		upd(rc,mid+1,e,i,j,v);
		pull(n);
	}
	ll query(int n, int b, int e, int i, int j)
	{
		if(b > j || e < i) return 0;
		if(b >= i && e <= j)
		{
			return t[n];
		}
		return combine(query(lc,b,mid,i, j),query(rc,mid+1,e,i,j));
	}
}t;


int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i<= n; i++)
	{
		cin >> a[i]; 
	}
	t.build(1,1,n);
}	