#include<bits/stdc++.h>
#define ll long long
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;
const int N = 2e5+9;
const ll inf = 1e14+9;
int a[N];
long long t[4*N],lazy[4*N];
void push(int n, int b, int e)
{
	if(lazy[n] == 0) return;
	t[n] = t[n] + lazy[n];
	if(b!=e)
	{
		lazy[lc] += lazy[n];
		lazy[rc] += lazy[n];
	}
	lazy[n] = 0;
}
void build(int n, int b, int e)
{
	if(b==e)
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
	if(b>j || e<i) return;
	if(b>=i && e<=j)
	{
		lazy[n] = v;
		push(n,b,e);
		return;
	}
	upd(lc,b,mid,i,j,v);
	upd(rc,mid+1,e,i,j,v);
	t[n] = min(t[lc],t[rc]);
}
ll query(int n, int b,  int e, int i, int j)
{
	push(n,b,e);
	if(b>j || e<i) return inf;
	if(b>=i && e<=j) return t[n];
	return min(query(lc,b,mid,i,j),query(rc,mid+1,e,i,j));
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
	cin.ignore();
	while(q--)
	{
		string line;
		getline(cin, line);
		stringstream ss(line);
		int l, r, v;
		ss >> l >> r;
		l++,r++;
		if(ss>>v)
		{
			// update
			if(r<l)
			{
				upd(1,1,n,l,n,v);
				upd(1,1,n,1,r,v);
			}
			else{
				upd(1,1,n,l,r,v);
			}
		}
		else{
			// query
			ll ans = inf;
			if(r<l)
			{
				ans = query(1,1,n,1,r);
				ans = min(ans,query(1,1,n,l,n));
			}
			else{
				ans = query(1,1,n,l,r);
			}
			cout << ans << endl;
		}
	
	}
}	