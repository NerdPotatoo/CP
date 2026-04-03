#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 9;
int t[N*4];
int a[N];

void build(int n, int b, int e)
{
	if(b == e)
	{
		t[n] = a[b];
		return;
	}
	int l = (2 * n), r = (2 * n) + 1;
	int mid = (b + e) >> 1;
	build(l, b, mid);
	build(r, mid+1, e);
	t[n] = t[l] ^ t[r];
}
ll query(int n, int b, int e, int i, int j)
{
	if(b > j || e < i) return 0;
	if(b >= i && e <= j)
	{
		return t[n];
	}
	int l = (2 * n), r = (2 * n) + 1;
	int mid = (b + e) >> 1;
	return query(l, b, mid, i, j) ^ query(r, mid+1, e, i, j);
}
void upd(int n, int b, int e, int i, int x)
{
	if(b > i || e < i) return;
	if(b == i && e == b)
	{
		t[n] = x;
		return;
	}
	int l = 2*n, r = 2*n+1;
	int mid = (b+e) >> 1;
	upd(l,b,mid,i,x);
	upd(r,mid+1,e,i,x);
	t[n] = t[l] ^ t[r];

}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(1,1,n);
	// cout << query(1,1,n,1,4) << endl;
	// for(int i = 1; i<=10; i++)

	// 	cout << t[i] << endl;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		cout << query(1,1,n,l,r) << endl;
	}

}	