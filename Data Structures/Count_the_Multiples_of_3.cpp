#include<bits/stdc++.h>
#define ll long long
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;
const int N = 1e5+9;
struct node{
	int occur[3];
};
node t[N*4];
int lazy[N*4];
node merge(node l, node r)
{
	node ans;
	for(int i = 0; i<3; i++)
	{
		ans.occur[i] = l.occur[i] + r.occur[i];
	}
	return ans;
}
void push(int n, int b, int e)
{
	if(lazy[n] == 0) return;
	node cur = t[n];
	for(int i = 0; i<3; i++)
	{
		t[n].occur[(i+lazy[n])%3] = cur.occur[i];
	}
	if(b!=e)
	{
		lazy[lc] = (lazy[lc] + lazy[n]) % 3;
		lazy[rc] = (lazy[rc] + lazy[n]) % 3;
	}
	lazy[n] = 0;
}
void build(int n, int b, int e)
{
	lazy[n] = 0;
	if(b==e)
	{
		t[n].occur[0] = 1;
		t[n].occur[1] = 0;
		t[n].occur[2] = 0;
		return;
	}
	build(lc,b,mid);
	build(rc,mid+1,e);
	t[n] = merge(t[lc],t[rc]);
}
void upd(int n, int b, int e, int i , int j, int v)
{
	push(n,b,e);
	if(b>j || e < i) return;
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
int query(int n, int b, int e, int i, int j)
{
	push(n,b,e);
	if(b>j || e < i) return 0;
	if(b>=i && e<=j)
	{
		return t[n].occur[0];
	}
	return query(lc,b,mid,i,j) + query(rc,mid+1,e,i,j);
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt,cs = 0; cin >> tt;
	while(tt--)
	{
		cout << "Case " << ++cs << ":\n";
		int n, q; cin >> n >> q;
		build(1,0,n-1);
		while(q--)
		{
			int ty; cin >> ty;
			if(!ty)
			{
				int l , r;
				cin >> l >> r;
				upd(1,0,n-1,l,r,1);
			}
			else{
				int l, r; cin >> l >> r;
				cout << query(1,0,n-1,l,r) << endl;
			}
		}
	}
}	
