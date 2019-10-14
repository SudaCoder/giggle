#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int n, m, cas = 0;
unsigned a[N], A, B, C;
unsigned ans[110];
struct qu {
    int b, id;
    bool operator<(const qu &rhs) const {
        return b < rhs.b;
    }
} q[110];

unsigned x = A, y = B, z = C;
unsigned rng61() {
    unsigned t;
    x = x ^ (x << 16);
    x = x ^ (x >> 5);
    x = x ^ (x << 1);
    t = x;
    x = y;
    y = z;
    z = (t ^ x) ^ y;
    return z;
}

int main() {
    while(~scanf("%d%d%u%u%u", &n, &m, &A, &B, &C)) {
        x = A;
        y = B;
        z = C;
        for(int i = 0; i < n; ++i) {
            a[i] = rng61();
        }
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &q[i].b);
            q[i].id = i;
        }
        sort(q + 1, q + m + 1);
        q[m + 1].b = n - 1;
        q[m + 1].id = 0;
        nth_element(a, a + n - 1, a + n);
        ans[0] = a[n - 1];
        for(int i = m; i; --i) {
            if(q[i].b == q[i + 1].b) {
                ans[q[i].id] = ans[q[i + 1].id];
                continue;
            }
            nth_element(a, a + q[i].b, a + q[i + 1].b);
            ans[q[i].id] = a[q[i].b];
        }
        printf("Case #%d:", ++cas);
        for(int i = 1; i <= m; ++i) {
            printf(" %u", ans[i]);
        }
        puts("");
    }
    return 0;
}