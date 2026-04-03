#include<bits/stdc++.h>
#define ll long long
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;
const int N = 1e5+9, inf = 1e9+9;
int a[N];
struct Node{
	int g, mn, mn_cnt;
};
Node t[4*N];
Node merge(Node l, Node r)
{
	Node ans;
	ans.g = __gcd(l.g,r.g);
	ans.mn = min(l.mn,r.mn);
	ans.mn_cnt = 0;
	if(l.mn == ans.mn)
	{
		ans.mn_cnt += l.mn_cnt ;
	}
	if(r.mn == ans.mn)
	{
		ans.mn_cnt += r.mn_cnt;
	}
	return ans;
}
void build(int n, int b, int e)
{
	if(b == e)
	{
		t[n].g = t[n].mn = a[b];
		t[n].mn_cnt = 1;
		return;
	}
	build(lc,b,mid);
	build(rc,mid+1,e);
	t[n] = merge(t[lc],t[rc]);
}
Node query(int n, int b, int e, int i , int j)
{
	if(b>j || e<i) return {0,inf,0};
	if(b>=i && e<=j) return t[n];
	return merge(query(lc,b,mid,i,j),query(rc,mid+1,e,i,j));
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
	}
	build(1,1,n);
	int q; cin >> q;
	while(q--)
	{
		int l, r; cin >> l >> r;
		Node ans = query(1,1,n,l,r);
		int freed = 0;
		if(ans.g == ans.mn)
		{
			freed = ans.mn_cnt;
		}
		cout << (r - l + 1) - freed << endl;
	}
}	