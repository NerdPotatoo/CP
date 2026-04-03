#include<bits/stdc++.h>
#define ll long long
#define lc (n<<1)
#define rc ((n<<1)+1)
#define mid ((b+e)>>1)
using namespace std;
const int N = 1e5+9, B = 30;
int L[N], R[N], AND[N], ans[N], t[N*4], f[N];
void build(int n, int b, int e)
{
	if(b==e)
	{
		t[n] = ans[b];
		return;
	}
	build(lc,b,mid);
	build(rc,mid+1,e);
	t[n] = t[lc]&t[rc];
}
int query(int n, int b, int e, int i, int j)
{
	if(b>j || e<i) return ((1<<B)-1);
	if(b>=i && e<=j) return t[n];
	return query(lc,b,mid,i,j)&query(rc,mid+1,e,i,j);
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i<=q; i++)
	{
		cin >> L[i] >> R[i] >> AND[i];
	}
	for(int k = 0; k<B; k++)
	{
		for(int i = 1; i<=n; i++)
		{
			f[i] = 0;
		}
		for(int i = 1; i<=q; i++)
		{
			if((AND[i]>>k)&1)
			{
				f[L[i]]++;
				f[R[i]+1]--;
			}
			
		}
		for(int i = 1; i<=n; i++)
		{
			f[i] += f[i-1];
		}

		for(int i = 1; i<=n; i++)
		{
			if(f[i])
			{
				ans[i] |= (1<<k);
			}
		}
	}
	build(1,1,n);
	for(int i = 1; i<=q; i++)
	{
		int cur_and = query(1,1,n,L[i],R[i]);
		if(cur_and != AND[i])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for(int i = 1; i<=n; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
}	