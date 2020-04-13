//1055B
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long a[N];
int fa[N], need, cnt, n, m, l;
int op, p, d;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return 0;
    fa[fx] = fy;
    return 1;
}

int main() {
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if (a[i] > l) need++;
        fa[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] > l && a[i + 1] > l)
            cnt += unite(i, i + 1);
    }
    while (m--) {
        scanf("%d", &op);
        if (op == 0)
            printf("%d\n", need - cnt);
        else {
            scanf("%d%d", &p, &d);
            if (a[p] <= l && a[p] + d > l) need++;
            a[p] += d;
            if (a[p] > l) {
                if (p != 1 && a[p - 1] > l)
                    cnt += unite(p, p - 1);
                if (p != n && a[p + 1] > l)
                    cnt += unite(p, p + 1);
            }
        }
    }
    return 0;
}