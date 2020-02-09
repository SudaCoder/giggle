#include <cstdio>
#include <cstring>
#include <algorithm>
using ll = long long;

const int N = 3e5+9;
using namespace std;
int n, m, a[N], b[N];

int main() {
    scanf("%d%d", &n, &m);
    ll sum_a = 0, sum_b = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum_a += a[i];
    }
    sort(a+1, a+1+n);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        sum_b += b[i];
    }
    sort(b+1, b+1+m);
    if (b[1] < a[n]) {
        return puts("-1"), 0;
    }
    long long ans = 1LL*m*sum_a + sum_b;
    if (b[1] == a[n]) {
        ans -= 1LL * m * a[n];
    } else {
        ans -= (m - 1LL) * a[n] + a[n-1];
    }
    printf("%lld\n", ans);
    return 0;
}