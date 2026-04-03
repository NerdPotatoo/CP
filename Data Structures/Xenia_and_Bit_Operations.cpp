#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+9;
int a[N], t[N*4];
int merge(int l, int r, int b, int e)
{
	int pw = 0, len = e-b+1;
	while(len > 1)
	{
		pw++;
		len/=2;
	}
	if(pw&1) return l | r;
	else return l ^ r;
}
void build(int n, int b, int e)
{
	if(b==e)
	{
		t[n] = a[b];
		return;
	}
	int lc = n<<1 , rc = lc|1, mid = (b+e)>>1;
	build(lc,b,mid);
	build(rc,mid+1,e);
	t[n] = merge(t[lc],t[rc],b,e);
}

void upd(int n, int b, int e, int i, int v)
{
	if(b > i or e < i) return;
	if(b==i && e == b)
	{
		t[n] = v;
		return;
	}
	int lc = n<<1 , rc = lc|1, mid = (b+e)>>1;
	upd(lc,b,mid,i,v);
	upd(rc,mid+1,e,i,v);
	t[n] = merge(t[lc],t[rc],b,e);

}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= (1<<n); i++)
	{
		cin >> a[i];
	}
	build(1,1,1<<n);
	int i,v;
	while(q--)
	{
		cin >> i >> v;
		upd(1,1,(1<<n),i,v);
		cout << t[1] << endl;
	}
}	