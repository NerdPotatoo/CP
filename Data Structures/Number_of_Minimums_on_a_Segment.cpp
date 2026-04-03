#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 9,inf = 1e9 + 9;

struct Node{
	int mn;
	int cnt;
};

Node t[N*4];
int a[N];
Node merge(const Node& a, const Node& b)
{
	if(a.mn < b.mn) return a;
	if(a.mn > b.mn) return b;
	return {a.mn, a.cnt + b.cnt};
}
void build(int n, int b, int e)
{
	if(b == e)
	{
		t[n] = {a[b],1};
		return;
	}

	int l = 2 * n, r = 2 * n + 1;
	int mid = (b+e) >> 1;
	build(l, b, mid);
	build(r, mid + 1, e);
	t[n] = merge(t[l],t[r]);
}
Node query(int n, int b, int e, int i, int j)
{
	if(b > j || e < i) return {inf, 0};
	if(b >= i && e <= j) return t[n];
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b+e) >> 1;
	Node left = query(l, b, mid, i, j);
	Node right = query(r, mid + 1, e, i, j);
	return merge(left, right);
}

void update(int n, int b, int e, int i, int x)
{
	if(b > i || e < i) return;
	if(b == i && e == b) {
		t[n] = {x,1};
		return;
	}
	int l = 2 * n, r = 2 * n + 1;
	int mid = (b+e) >> 1;
	update(l, b, mid, i, x);
	update(r, mid + 1, e, i, x);
	t[n] = merge(t[l], t[r]);
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
	while(q--)
	{

		int ty, l, r, i, x;
		cin >> ty;
		if(ty == 1)
		{
			cin >> i >> x;
			// cout << "update ";
			update(1,1,n,i+1,x);

		}
		else{
			cin >> l >> r;
			Node ans = query(1, 1, n, l+1, r);
			cout << ans.mn << " " << ans.cnt << endl;
		}
		
	}

}	