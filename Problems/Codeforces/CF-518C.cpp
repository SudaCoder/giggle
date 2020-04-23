//518C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, k;
int a[N], pos[N];
long long ans;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    while (m--) {
        int x;
        scanf("%d", &x);
        ans += 1 + (pos[x] - 1) / k;
        if (pos[x] != 1) {
            int y = a[pos[x] - 1];
            swap(a[pos[x]], a[pos[x] - 1]);
            pos[x]--;
            pos[y]++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}