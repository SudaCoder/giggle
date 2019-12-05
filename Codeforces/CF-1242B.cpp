#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

const int N = 1e5+9;
using namespace std;
int n, m, u, v, head[N], cnt, fa[N], siz[N], pa[N];

struct Edge {
    int v, nxt;
} e[N];

void ad(int u, int v) {
    e[cnt] = {v, head[u]};
    head[u] = cnt++;
}

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        siz[i] = 1;
        fa[i] = i;
        pa[i] = 0;
    }
}

int Find(int x) {
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Union(int fx, int fy) {
    // fx,fy father
    fa[fx] = fy;
    siz[fy] += siz[fx];
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        if (u < v) swap(u, v);
        ad(u, v);
    }
    int ans = n - 1;
    vector<int> zeros;
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; ~j; j = e[j].nxt) {
            pa[Find(e[j].v)]++;
        }
        vector<int> tmp;
        for (auto v: zeros) {
            // printf("%d %d %d %d\n", i, v, siz[v], pa[v]);
            if (siz[v] > pa[v]) {
                Union(v, i);
                ans --;
            } else tmp.push_back(v);
            pa[v] = 0;
        }
        zeros = tmp;
        zeros.push_back(i);
    }

    printf("%d\n", ans);
    return 0;
}