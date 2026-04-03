#include<bits/stdc++.h>
#define ll long long
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;
const int N = 1e5+9;
int a[N];
struct Node{
	ll sum;
	ll mn;
};
Node t[N*4];
ll lazy[N*4];
void push(int n, int b, int e)
{
	if(lazy[n] == 0) return;
	t[n].sum = t[n].sum + (e-b+1) * lazy[n];
	t[n].mn += lazy[n];
	if(b!=e)
	{
		lazy[lc] += lazy[n];
		lazy[rc] += lazy[n];
	}
	lazy[n] = 0;
}
Node merge(Node a, Node b)
{
	Node c;
	c.sum = a.sum + b.sum;
	c.mn = min(a.mn,b.mn);
	return c;
}
void build(int n, int b, int e)
{
	lazy[n] = 0;
	if(b==e)
	{
		t[n].sum = t[n].mn = a[b];
		return;
	}

	build(lc, b, mid);
	build(rc, mid+1, e);
	t[n] = merge(t[lc],t[rc]);
}
void upd(int n, int b, int e, int i, int j, int v)
{
	push(n,b,e);
	if(b > j || e < i) return;
	if(b>=i && e <=j)
	{
		lazy[n] = v;
		push(n,b,e);
		return;
	}
	upd(lc,b,mid,i,j,v);
	upd(rc,mid+1,e,i,j,v);
	t[n] = merge(t[lc],t[rc]);
}
Node query(int n, int b, int e, int i , int j)
{
	push(n,b,e);
	if(b > j || e < i) return {-1,-1};
	if(b>=i && e <=j)
	{
		return t[n];
	}
	Node left = query(lc,b,mid,i,j);
	Node right = query(rc,mid+1,e,i,j);
	if(left.sum == -1) return right;
	else if(right.sum == -1) return left;
	else return merge(left,right);
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
			cin >> l >> r >>v;
			l++;
			upd(1,1,n,l,r,v);
		}
		else{
			int i, j; cin >> i >> j;
			i++;
			Node ans = query(1,1,n,i,j);
			cout << ans.mn << endl;
		}
	}
}	
