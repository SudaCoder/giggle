#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

vector<int> tmp, now;
vector<pair<int, int>> G[N];
int fa[N], dep[N], val[N], n, m, k, cas;
long long tot, ans;

struct node {
	int val, x, y;
	bool operator<(const node &rhs) const {
		return val < rhs.val;
	}
};

void merge(vector<int> &now, vector<int> &rhs) {
	sort(now.begin(), now.end(), greater<int>());
	sort(rhs.begin(), rhs.end(), greater<int>());
	tmp.clear();
	priority_queue<node> pq;
	for(int i = 0; i < rhs.size(); ++i) {
		pq.push((node){now[0] + rhs[i], 0, i});
	}
	while(tmp.size() < k && !pq.empty()) {
		node u = pq.top();
		pq.pop();
		tmp.push_back(u.val);
		if(u.x + 1 < now.size()) {
			pq.push((node){now[u.x + 1] + rhs[u.y], u.x + 1, u.y});
		}
	}
	now = tmp;
}

void dfs(int rt, int pre, int depth, int value) {
	dep[rt] = depth;
	fa[rt] = pre;
	val[rt] = value;
	for(int i = 0; i < G[rt].size(); ++i) {
		pair<int, int> u = G[rt][i], tmp;
		if(u.first == pre) continue;
		if(dep[u.first]) {
			if(dep[u.first] < dep[rt]) {
				vector<int> v;
				v.push_back(u.second);
				tmp = make_pair(rt, val[rt]);
				while(tmp.first != u.first) {
					v.push_back(tmp.second);
					tmp = make_pair(fa[tmp.first], val[fa[tmp.first]]);
				}
				merge(now, v);
			}
			continue;
		}
		dfs(u.first, rt, depth + 1, u.second);
	}
}

int main() {
	now.reserve(1000001); tmp.reserve(1000001);
	while(~scanf("%d%d", &n, &m)) {
		tot = 0;
		for(int i = 1; i <= m; ++i) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			G[a].push_back(make_pair(b, c));
			G[b].push_back(make_pair(a, c));
			tot += c;
		}
		now.clear();
		now.push_back(0);
		scanf("%d", &k);
		for(int i = 1; i <= n; ++i) {
			if(!dep[i])
				dfs(i, 0, 1, 0);
		}
		ans = 0;
		for(int i = 0; i < now.size(); ++i)
			ans += 1LL * (i + 1) * (tot - now[i]);
		printf("Case #%d: %lld\n", ++cas, ans % (1LL << 32));
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			dep[i] = 0;
		}
	}
	return 0;
}
