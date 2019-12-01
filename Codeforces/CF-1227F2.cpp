#include <cstdio>
#include <iostream>
using ll = long long;
const int N = 2e5+9;
const int mod = 998244353;
using namespace std;
int n;
ll k, t = 0, fac[N], inv[N];
int x[N];

ll qp(ll a, ll k) {
    ll ans = 1;
    while (k) {
        if (k & 1) ans = ans * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return ans;
}

void init() {
    fac[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i-1] * i % mod;
    }
    inv[N-1] = qp(fac[N-1], mod-2);
    for (int i = N-2; i; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
}

int main() {
    init();
    scanf("%d%lld", &n, &k);
    t = n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        if (i && x[i] == x[i-1]) t--;
    }
    if (x[0] == x[n-1]) t--;
    ll ans = 0, tmp = 1;
    for (int i = 0; i < t; i++) {
        ll sum = qp(2, t-i);
        if ((t - i) & 1) {
            sum = sum * inv[2] % mod;
        } else {
            sum = (sum - fac[t-i]*inv[t-i>>1]%mod*inv[t-i>>1]%mod) % mod;
            if (sum < 0) sum += mod;
            sum = sum * inv[2] % mod;
        }
        // cout << sum << " " << fac[t] << " " << t << " " << ans << tmp << endl;
        ans = (ans + sum * tmp % mod * fac[t] % mod * inv[i] % mod * inv[t-i] % mod) % mod;
        tmp = tmp * (k - 2) % mod;
    }
    printf("%lld\n", ans * qp(k, n - t) % mod);
    return 0;
}