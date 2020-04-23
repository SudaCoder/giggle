//462B
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, k, cnt[26];
char s[N];
long long ans;

int main() {
    scanf("%d%d%s", &n, &k, s);
    for (int i = 0; i < n; ++i)
        cnt[s[i] - 'A']++;
    sort(cnt, cnt + 26);
    for (int i = 25; i >= 0; --i) {
        if (k == 0) break;
        int tmp = min(k, cnt[i]);
        ans += 1LL * tmp * tmp;
        k -= tmp;
    }
    printf("%lld\n", ans);
    return 0;
}