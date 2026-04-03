#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define lc  (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
const int N = 1e5+9;
string a;
struct node{
	int ones, zeros;
};
node t[4*N];
bool lazy[4*N];
void push(int n, int b, int e)
{
	if(lazy[n] == false) return;
	swap(t[n].ones,t[n].zeros);
	if(b!=e)
	{
		lazy[lc] ^= true;
		lazy[rc] ^= true;
	}
	lazy[n] = false;
}
node merge(node a, node b)
{
	node c;
	c.ones = a.ones + b.ones;
	c.zeros = a.zeros + b.zeros;
	return c;
}
void build(int n, int b, int e)
{
	lazy[n] = false;
	if(b == e)
	{
		t[n].ones = t[n].zeros = 0;
		if(a[b] == '1') t[n].ones = 1;
		else t[n].zeros = 1;
		return;
	}
	build(lc, b, mid);
	build(rc, mid+1, e);
	t[n] = merge(t[lc],t[rc]);
}
void upd(int n, int b, int e, int i, int j)
{
	push(n,b,e);
	if(b > j || e < i) return;
	if(b >= i && e <= j)
	{
		lazy[n] = true;
		return;
	}
	upd(lc,b,mid,i,j);
	upd(rc,mid+1,e,i,j);
	t[n] = merge(t[lc],t[rc]);
}
node query(int n, int b, int e, int i, int j)
{
	push(n,b,e);
	if(b > j || e < i) return {0,0};
	if(b >= i && e <= j)
	{
		return t[n];
	}
	return merge(query(lc,b,mid,i,j),query(rc,mid+1,e,i,j));
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt, cs = 0; cin >> tt;
	while(tt--)
	{
		cin >> a;
		int n = a.size();
		build(1,0,n-1);
		int q; cin >> q;
		cout << "Case " << ++cs << ":\n";
		while(q--)
		{
			char ty; cin >> ty;
			if(ty == 'I')
			{
				int l, r;
				cin >> l >> r;
				// update
				l--,r--;
				upd(1,0,n-1,l,r);
			}
			else{
				int i; cin >> i;
				// query
				i--;
				if(query(1,0,n-1,i,i).zeros == 1)
					cout << 0 << '\n';
				else 
					cout << 1 << '\n';  
			}
		}
	}
}	