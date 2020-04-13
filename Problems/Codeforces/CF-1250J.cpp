#include <cstdio>
#include <iostream>
const int N = 3e4 + 9;
using ll = long long;

using namespace std;
int t, n;
ll c[N], tmp[N], k;

bool check(ll row_num) {
    if (row_num == 0)
        return 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        tmp[i] = c[i];
    }
    for (int i = 1; i <= n; i++) {
        if (tmp[i] + tmp[i - 1] >= row_num) {
            ans += 1;
            tmp[i] -= row_num - tmp[i - 1];
            tmp[i - 1] = 0;
        }
        ans += tmp[i] / row_num;
        tmp[i] %= row_num;
    }
    return ans >= k;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld", &n, &k);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &c[i]);
            sum += c[i];
        }
        ll l = 0, r = sum / k;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (check(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%lld\n", (l - 1) * k);
    }
    return 0;
}