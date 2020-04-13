//873B
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int sum[N], l[N * 2], r[N * 2], ans, n;
char s[N];

int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1];
        if (s[i] == '1')
            sum[i]++;
        else
            sum[i]--;
    }
    memset(l, -1, sizeof(l));
    l[N] = 0;
    for (int i = 1; i <= n; ++i) {
        r[sum[i] + N] = i;
        if (l[sum[i] + N] == -1)
            l[sum[i] + N] = i;
    }
    for (int i = N - n; i <= N + n; ++i) {
        if (l[i] != -1)
            ans = max(ans, r[i] - l[i]);
    }
    printf("%d\n", ans);
    return 0;
}