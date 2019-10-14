#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector<int> G[N];
int n, c[N], cas, vis[N], sz[N], cnt, sum[N];
long long ans;

long long gao(int n) {return 1LL * n * (n - 1) / 2;}

void dfs(int rt, int fa) {
	sz[rt] = 1;
	int tot = 0;
	for(auto i: G[rt]) {
		if(i == fa) continue;
		int last = sum[c[rt]];
		dfs(i, rt);
		sz[rt] += sz[i];
		int add = sum[c[rt]] - last;
		ans -= gao(sz[i] - add);
		tot += sz[i] - add;
	}
	sum[c[rt]] += tot + 1;
	if(rt == 1) {
		for(int col = 1; col <= n; ++col) {
			if(!vis[col]) continue;
			ans -= gao(sz[rt] - sum[col]);
		}
	}
}

int main() {
	while(~scanf("%d", &n)) {
		cnt = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &c[i]);
			vis[c[i]] = 1;
		}
		for(int i = 1; i <= n; ++i)
			cnt += vis[i];
		for(int i = 1; i < n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		ans = 1LL * cnt * n * (n - 1) / 2;
		dfs(1, 0);
		printf("Case #%d: %lld\n", ++cas, ans);
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			sum[c[i]] = 0;
			vis[c[i]] = 0;
		}
	}
	return 0;
}