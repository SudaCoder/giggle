#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
const int N = 3e5+9;
struct P {
  ll x, y, id;
} p[N], q[N];

bool cmp (P a, P b) {
    return a.x - a.y < b.x - b.y;
}

ll sumx[N], sumy[N], ans[N];

int main() {
    scanf("%d %d", &n, &m);
    int x, y;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
        p[i].id = i;
        q[i] = p[i];
    }
    sort(p+1, p+n+1, cmp);
    for (int i = 1; i <= n; i++) {
        sumx[i] = sumx[i-1] + p[i].x;
        sumy[i] = sumy[i-1] + p[i].y;
    }
    for (int i = 1; i <= n; i++) {
        ans[p[i].id] = (n - i) * p[i].x;
        ans[p[i].id] += sumx[i-1];
        ans[p[i].id] += (i - 1) * p[i].y;
        ans[p[i].id] += sumy[n] - sumy[i];
    }
    int a, b;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ll v = min(q[a].x + q[b].y, q[a].y + q[b].x);
        ans[a] -= v;
        ans[b] -= v;
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld%c", ans[i], " \n"[i==n]);
    }
    return 0;
}
