#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 1e4 + 10;

int mn, mx[N], size[N], fa[N];
int dis[N], vis[N], head[N], pnt[N << 1], nxt[N << 1], val[N << 1], cnt;
int n, k, root, ans, num;

void add(int x, int y, int v) {
    pnt[cnt] = y;
    val[cnt] = v;
    nxt[cnt] = head[x];
    head[x] = cnt++;
}

void dfssize(int u, int pre) {
    fa[u] = pre;
    size[u] = 1;
    mx[u] = 0;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(vis[v] || v == pre) continue;
        dfssize(v, u);
        size[u] += size[v];
        mx[u] = max(mx[u], size[v]);
    }
}

void dfsroot(int u, int pre, int tot) {
    mx[u] = max(mx[u], tot - size[u]);
    if(mx[u] < mn) {
        mn = mx[u];
        root = u;
    }
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(vis[v] || v == pre) continue;
        dfsroot(v, u, tot);
    }
}


void dfsdis(int u, int pre, int d) {
    dis[num++] = d;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(vis[v] || v == pre) continue;
        dfsdis(v, u, d + val[i]);
    }
}

int calc(int u, int d) {
    int res = 0;
    num = 0;
    dfsdis(u, 0, d);
    sort(dis, dis + num);
    int i = 0, j = num - 1;
    while(i < j) {
        while(i < j && dis[i] + dis[j] > k)
            j--;
        res += j - i;
        i++;
    }
    return res;
}

void dfs(int u, int pre) {
    mn = n;
    root = u;
    dfssize(u, 0);
    dfsroot(u, 0, size[u]);
    ans += calc(root, 0);
    vis[root] = 1;
    for(int i = head[root]; ~i; i = nxt[i]) {
        int v = pnt[i];
        if(vis[v] || v == pre) continue;
        ans -= calc(v, val[i]);
        dfs(v, root);
    }
}

void init() {
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    cnt = ans = 0;
}


int main() {
    while(~scanf("%d%d", &n, &k) && n) {
        init();
        int u, v, l;
        for(int i = 1; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &l);
            add(u, v, l);
            add(v, u, l);
        }
        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}