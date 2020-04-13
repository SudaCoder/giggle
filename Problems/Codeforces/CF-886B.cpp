// 886B
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N], vis[N], ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = n; i; --i) {
        if (vis[a[i]] == 0)
            ans = a[i];
        vis[a[i]] = 1;
    }
    printf("%d\n", ans);
    return 0;
}