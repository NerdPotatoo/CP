#include<bits/stdc++.h>
#define ll long long
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;

const int N = 1e6+9;
ll t[N*4];
int d[N], a[N];
void build(int n, int b, int e)
{
	if(b==e)
	{
		t[n] = a[b];
		return;
	}
	build(lc,b,mid);
	build(rc,mid+1,e);
	t[n] = t[lc] + t[rc];
}

void upd(int n, int b, int e, int i , int v)
{
	if(b > i || e < i) return ;
	if(b==i && b==e)
	{
		t[n] = v;
		return;
	}
	upd(lc,b,mid,i,v);
	upd(rc,mid+1,e,i,v);
	t[n] = t[lc]+t[rc];
}

ll query(int n, int b, int e, int i ,int j)
{
	if(b > j || e < i) return 0;
	if(b>=i && e<=j)
	{
		return t[n];
	}
	return query(lc,b,mid,i,j) + query(rc,mid+1,e,i,j);
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 1 ; i<N; i++)
	{
		for(int j = i; j<N; j+=i)
		{
			d[j]++;
		}
	}

	int n, q;
	cin >> n >> q;
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
	}
	build(1,1,n);
	set<int> alive;
	for(int i = 1; i<=n; i++)
	{
		if(a[i] > 2) alive.insert(i);
	}
	while(q--)
	{
		int ty, l, r;
		cin >> ty >> l >> r;
		if(ty == 1)
		{
			auto it = alive.lower_bound(l);
			vector<int> to_del;
			while(it != alive.end() && (*it) <= r)
			{
				int i = (*it);
				upd(1, 1, n, i, d[a[i]]);
				a[i] = d[a[i]];
				if(a[i] <= 2)
				{
					to_del.push_back(i);
				}
				it++;
			}

			for(int i : to_del)
			{
				alive.erase(i);
			}
		}
		else{
			cout << query(1,1,n,l,r) << '\n';
		}
	}
}	