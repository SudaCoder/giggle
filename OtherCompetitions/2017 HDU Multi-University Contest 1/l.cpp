#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;

int fac[N], facinv[N]; 
int n, cas, l[N], r[N], ans;

long long qp(long long a, long long n) {
	long long res = 1;
	while(n) {
		if(n & 1) 
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

void init() {
	fac[0] = fac[1] = 1;
	for(int i = 2; i < N; ++i)
		fac[i] = 1LL * i * fac[i - 1] % mod;
	facinv[N - 1] = qp(fac[N - 1], mod - 2);
	for(int i = N - 2; ~i; --i) 
		facinv[i] = 1LL * facinv[i + 1] * (i + 1) % mod;
}

int C(int n, int m) {
	return 1LL * fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}

vector<pair<int, int>> mp[N];

int find(int l, int r) {
	vector<pair<int, int>>::iterator s = lower_bound(mp[l].begin(), mp[l].end(), make_pair(r, 0));
	if(s == mp[l].end() || s->first != r) return 0;
	return s->second;
}

void dfs(int l, int r) {
	int pos = find(l, r);
	if(pos == 0) {
		ans = 0;
		return;
	}
	if(l == r) {
		if(pos != l) ans = 0;
		return;
	}
	if(pos == l) 
		dfs(l + 1, r);
	else if(pos == r)
		dfs(l, r - 1);
	else {
		ans = 1LL * ans * C(r - l, pos - l) % mod; 
		dfs(l, pos - 1);
		dfs(pos + 1, r);
	}
}

int main() {
	init();
	while(~scanf("%d", &n)) {
		ans = 1;
		for(int i = 1; i <= n; ++i) scanf("%d", &l[i]);
		for(int i = 1; i <= n; ++i) scanf("%d", &r[i]);
		for(int i = 1; i <= n; ++i) {
			mp[l[i]].emplace_back(r[i], i);
		}
		for(int i = 1; i <= n; ++i) sort(mp[i].begin(), mp[i].end());
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j + 1 < mp[i].size(); ++j)
				if(mp[i][j].first == mp[i][j + 1].first)
					ans = 0;
		}
		if(ans)
			dfs(1, n);
		printf("Case #%d: %d\n", ++cas, ans);
		for(int i = 1; i <= n; ++i) mp[i].clear();
	}
	return 0;
}