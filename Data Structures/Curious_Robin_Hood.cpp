#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
int a[N];
long long t[N*4];

void build(int n, int b, int e)
{
	if(b == e)
	{
		t[n] = a[b];
		return;
	}
	int lc = n << 1, rc = lc | 1;
	int mid = (b+e) >> 1;
	build(lc, b, mid);
	build(rc, mid+1, e);
	t[n] = t[lc] + t[rc];
}

long long query(int n, int b, int e, int i, int j)
{
	if(b > j || e < i) return 0;
	if(b >= i && e <= j) return t[n];
	int lc = n << 1, rc = lc | 1;
	int mid = (b+e) >> 1;
	return query(lc, b, mid, i, j) + query(rc, mid+1, e, i, j);
}
void add(int n, int b, int e, int x, int v)
{
	if(b > x || e < x) return;
	if(b == x && e == x)
	{
		t[n] += v;
		return;
	}
	int lc = n << 1, rc = lc | 1;
	int mid = (b+e) >> 1;
	add(lc, b, mid, x, v);
	add(rc, mid+1, e, x, v);
	t[n] = t[lc] + t[rc];
}
long long give(int n, int b, int e, int x)
{
	if(b > x || e < x) return 0;
	if(b == x && e == x)
	{
		long long g = t[n];
		t[n] = 0;
		return g;
	}
	int lc = n << 1, rc = lc | 1;
	int mid = (b+e) >> 1;
	int l = give(lc, b, mid, x);
	int r = give(rc, mid+1, e, x);
	t[n] = t[lc] + t[rc];
	return l+r;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt, cs = 0; cin >> tt;
	while(tt--)
	{
		int n, q;
		cin >> n >> q;
		for(int i = 1; i <= n ; i++)
		{
			cin >> a[i];
		}

		build(1,1,n);
		cout << "Case " << ++cs << ": " << endl;
		// for(int i = 1; i<=4*n; i++)
		// {
		// 	cout << t[i] << ' ';
		// }
		// cout << endl;
		int typ, i, j, v;
		while(q--)
		{
			cin >> typ;

			if(typ == 1)
			{
				// cout << typ << " -> ";
				cin >> i;
				cout <<  give(1, 1, n, i+1) << endl;
			}
			else if(typ == 2)
			{
				cin >> i >> v;
				add(1, 1, n, i+1, v);
			}
			else{
				// cout << typ << " -> ";
				cin >> i >> j;
				cout << query(1, 1, n, i+1, j+1) << endl;
			}
		}
	}
}	