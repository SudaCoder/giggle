#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using ll = long long;
const int N = 1e5 + 9;
using namespace std;
int n, m, w, c[N];
bool vis[N];
ll ans = 0;

struct P {
    int c, w, idx;
    P() {}
    P(int _c, int _w, int _idx) {
        c = _c;
        w = _w;
        idx = _idx;
    }
    bool operator<(const P x) const {
        return 1LL * c * w > 1LL * x.c * x.w;
    }
};

priority_queue<P> q;

int main() {
    while (q.size())
        q.pop();
    scanf("%d%d", &n, &m);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w);
        int re = c[i] % 100;
        if (re == 0)
            continue;
        q.push(P(100 - re, w, i));
        if (re > m) {
            m += 100;
            P tp = q.top();
            q.pop();
            ans += 1LL * tp.c * tp.w;
            // printf("%d %d %d\n", tp.c, tp.w, tp.idx);
            vis[tp.idx] = 1;
        }
        m -= re;
    }
    printf("%lld\n", ans);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", c[i] / 100 + vis[i], vis[i] ? 0 : c[i] % 100);
    }
}