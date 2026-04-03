#include<bits/stdc++.h>
#define ll long long
#define lc  (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;
const int N = 1e5+9, B = 20;

struct Node{
	int on[B], off[B];
};
Node t[4*N];
int a[N], lazy[4*N];
void push(int n, int b, int e)
{
	if(lazy[n] == 0) return;
	for(int k = 0; k<B; k++)
	{
		if((lazy[n]>>k)&1)
		{
			swap(t[n].on[k],t[n].off[k]);
		}
	}
	if(b!=e)
	{
		lazy[lc] ^= lazy[n];
		lazy[rc] ^= lazy[n];
	}
	lazy[n] = 0;
}
Node merge(Node l, Node r)
{
	Node ans;
	for(int k = 0; k<B; k++)
	{
		ans.on[k] = l.on[k] + r.on[k];
		ans.off[k] = l.off[k] + r.off[k];
	}
	return ans;
}
void build(int n, int b, int e)
{
	lazy[n] = 0;
	if(b == e)
	{
		for(int k = 0; k<B; k++)
		{

			if((a[b]>>k)&1)
			{
				t[n].on[k] = 1;
				t[n].off[k] = 0;
			}
			else{
				t[n].on[k] = 0;
				t[n].off[k] = 1;
			}
		}
		return;
	}

	build(lc,b,mid);
	build(rc,mid+1,e);
	t[n] = merge(t[lc],t[rc]);
}
void upd(int n, int b, int e, int i, int j, int v)
{
	push(n,b,e);
	if(b>j || e<i) return;
	if(b>=i && e<=j)
	{
		lazy[n] = v;
		push(n,b,e);
		return;
	}
	upd(lc,b,mid,i,j,v);
	upd(rc,mid+1,e,i,j,v);
	t[n] = merge(t[lc],t[rc]);
}
Node query(int n, int b, int e, int i, int j)
{
	push(n,b,e);
	if(b>j || e<i) {
		Node zero;
		memset(zero.on, 0, sizeof zero.on);
		memset(zero.off, 0, sizeof zero.off);
		return zero;
	}
	if(b>=i && e<=j)
	{
		return t[n];
	}
	return merge(query(lc,b,mid,i,j),query(rc,mid+1,e,i,j));
}
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
	while(q--)
	{
		int ty; cin >> ty;
		if(ty == 1)
		{
			int l, r; cin >> l >> r;
			Node ans = query(1,1,n,l,r);
			ll val = 0;
			for(int k = 0; k<B; k++)
			{
				val += (1LL * ans.on[k] * (1<<k));
			}
			cout << val << endl;
		}
		else{
			int l, r, v; cin >> l >> r >> v;
			upd(1,1,n,l,r,v);
		}
	}
}	