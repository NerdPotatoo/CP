#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
int a[N];
struct Node{
	int first_ele, first_ele_occur;
	int last_ele, last_ele_occur;
	int size;
};
Node t[N*4];
Node merge(Node l, Node r)
{
	if(l.first_ele == -1) return r;
	if(r.first_ele == -1) return l;
	Node ans;
	ans.first_ele = l.first_ele;
	ans.first_ele_occur = l.first_ele_occur;

	ans.last_ele = r.last_ele;
	ans.last_ele_occur = r.last_ele_occur;

	if(l.first_ele == r.first_ele)
	{
		ans.first_ele_occur += r.first_ele_occur;
	}
	if(l.last_ele == r.last_ele)
	{
		ans.last_ele_occur += l.last_ele_occur;
	}

	ans.size = max(l.size, r.size);
	if(l.last_ele == r.first_ele)
	{
		ans.size = max(ans.size, l.last_ele_occur + r.first_ele_occur);
	}
	return ans;
}
void build(int n, int b, int e)
{
	if(b == e)
	{
		t[n].first_ele = t[n].last_ele = a[b];
		t[n].first_ele_occur = t[n].last_ele_occur = 1;
		t[n].size = 1;
		return;
	}
	int lc = n << 1 , rc = lc | 1, mid = (b+e) >> 1;
	build(lc, b, mid);
	build(rc, mid+1, e);
	t[n] = merge(t[lc], t[rc]);
}
Node query(int n, int b, int e, int i, int j)
{
	if(b>j || e<i) return {-1,-1,-1,-1,-1};
	if(b>=i && e<=j) return t[n];

	int lc = n<<1, rc = lc|1, mid = (b+e)>>1;
	return merge(query(lc,b,mid,i,j), query(rc,mid+1,e,i,j));
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt, cs = 0; cin >> tt;
	while(tt--)
	{
		int n, c, q;
		cin >> n >> c >> q;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		build(1,1,n);
		int i,j;
		Node ans;
		cout << "Case " << ++cs << ":\n";
		while(q--)
		{
			cin >> i >> j;
			ans = query(1,1,n,i,j);
			cout << ans.size << endl;
		}
		// for(int i = 1; i<=30; i++)
		// {
		// 	cout << "[ " << t[i].cat << " , " << t[i].cnt << "]\n";
		// }
	}
}	