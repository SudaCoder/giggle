/*
题意：用 1 到 n 运送k 个货物，m条边,每条边表示 运送 x
单元货物的花费为a*x^2，c表示最大流量，求最小费用，若不能全部运送输出 -1;(c <= 5)
解析：对于每条边，我们进行拆边。对于一条u->v的边，系数为a，最大流为c,
我们可以拆成c条，每条流量都为1，系数分别为a, 3a, 5a, 7a …
这样我们选取最小的x条，就能得到a*x^2
*/
#include <bits/stdc++.h>
const int N = 120;
const int M = 4e5 + 9;
const int inf = 1e9 + 7;
using namespace std;

int d[N], head[N];
bool vis[N], inq[N];
int n, m, k, s, t, cnt, ans;

struct Edge {
  int v, w, c, nxt;
} e[M];
inline void ad(int u, int v, int w, int c) {
  e[cnt] = {v, w, c, head[u]};
  head[u] = cnt++;
}
inline void add(int u, int v, int w, int c) {
  ad(u, v, w, c);
  ad(v, u, 0, -c);
}
inline void init() {
  ans = cnt = 0;
  memset(head, -1, sizeof head);
}

bool spfa() {
  for (int i = 0; i <= t; i++)
    d[i] = inf;
  deque<int> q;
  q.push_back(s);
  d[s] = inq[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    inq[u] = 0;
    for (int i = head[u]; ~i; i = e[i].nxt) {
      int v = e[i].v;
      if (e[i].w > 0 && d[v] > d[u] + e[i].c) {
        d[v] = d[u] + e[i].c;
        if (!inq[v]) {
          inq[v] = 1;
          if (!q.empty() && d[v] < d[q.front()])
            q.push_front(v);
          else
            q.push_back(v);
        }
      }
    }
  }
  return d[t] < inf;
}

int dfs(int u, int w) {
  vis[u] = 1;
  if (u == t)
    return w;
  int dlt = w, x;
  for (int i = head[u]; ~i; i = e[i].nxt) {
    int v = e[i].v;
    if (!vis[v] && e[i].w > 0 && d[u] + e[i].c == d[v]) {
      x = dfs(v, min(dlt, e[i].w));
      e[i].w -= x;
      e[i ^ 1].w += x;
      ans += x * e[i].c;
      dlt -= x;
      if (!dlt)
        return w;
    }
  }
  return w - dlt;
}

inline int dinic() {
  int sum = 0;
  while (spfa()) {
    do {
      for (int i = 0; i <= t; i++)
        vis[i] = 0;
      sum += dfs(s, k);
    } while (vis[t]);
  }
  return sum;
}

int main() {
  std::ios::sync_with_stdio(0);
  while (cin >> n >> m >> k) {
    init();
    int u, v, w, a;
    s = 0, t = n;
    add(s, 1, k, 0);
    for (int i = 0; i < m; i++) {
      cin >> u >> v >> a >> w;
      for (int i = 1; i <= min(w, k); i++)
        add(u, v, 1, a * (2 * i - 1));
    }
    if (dinic() >= k)
      cout << ans << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}