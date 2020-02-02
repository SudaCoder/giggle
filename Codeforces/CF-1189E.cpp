#include <cstdio>
#include <unordered_map>

using namespace std;
int n, p, k, x;
unordered_map<int, int> mp;

inline int cal(int x) {
    return x * ((1LL*x*x%p*x%p-k+p)%p) % p;
}

int main() {
    scanf("%d%d%d", &n, &p, &k);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        int v = cal(x);
        ans += mp[v];
        mp[v] ++;
    }
    printf("%lld\n", ans);
    return 0;
}