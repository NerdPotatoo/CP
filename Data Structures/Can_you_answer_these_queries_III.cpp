#include<bits/stdc++.h>
#define ll long long
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;
const int N = 5e4+9, inf = 1e9+9;
int a[N];
struct Node{
	int mx_pref, mx_suff, tot, sub_mx;
};
Node t[4*N];
Node merge(Node l, Node r)
{
	if(l.tot == inf) return r;
	if(r.tot == inf) return l;
	Node ans;
	ans.sub_mx = max(l.sub_mx,r.sub_mx);
	ans.sub_mx = max(ans.sub_mx, l.mx_suff + r.mx_pref);

	ans.mx_pref = max(l.mx_pref , l.tot + r.mx_pref);
	ans.mx_suff = max(r.mx_suff, r.tot + l.mx_suff);
	ans.tot = l.tot + r.tot;
	return ans;
}
void build(int n, int b, int e)
{
	if(b==e)
	{

		t[n].mx_pref = a[b];
		t[n].mx_suff = a[b];
		t[n].sub_mx = a[b];
		t[n].tot = a[b];
		return;
	}
	build(lc,b,mid);
	build(rc,mid+1,e);
	t[n] = merge(t[lc],t[rc]);
}
void upd(int n, int b, int e, int i, int v)
{
	if(b>i || e<i) return;
	if(b==i && e==i)
	{
		t[n].mx_pref = v;
		t[n].mx_suff  = v;
		t[n].sub_mx = v;
		t[n].tot = v;
		return;
	}
	upd(lc,b,mid,i,v);
	upd(rc,mid+1,e,i,v);
	t[n] = merge(t[lc],t[rc]);
}
Node query(int n, int b, int e, int i, int j)
{
	if(b>j || e<i) return {inf, inf, inf, inf};
	if(b>=i && e<=j) return t[n];
	return merge(query(lc,b,mid,i,j), query(rc,mid+1,e,i,j));
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
		if(ty)
		{
			int i, j; cin >> i >> j;
			// ++i,++j;
			Node ans = query(1,1,n,i,j);
			cout << ans.sub_mx << '\n';
		}
		else{
			int i, v;
			cin >> i >> v;
			// ++i;
			upd(1,1,n,i,v);
		}
	}
}	