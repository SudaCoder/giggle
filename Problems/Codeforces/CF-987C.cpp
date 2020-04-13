//987C
#include <bits/stdc++.h>
using namespace std;

const int N = 3010;

int s[N], c[N], n, ans = 1e9;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &s[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);
    c[0] = 1e9;
    for (int j = 2; j < n; ++j) {
        int left = 0, right = 0;
        for (int i = 1; i < j; ++i) {
            if (s[i] < s[j] && c[i] < c[left])
                left = i;
        }
        for (int k = j + 1; k <= n; ++k) {
            if (s[j] < s[k] && c[k] < c[right])
                right = k;
        }
        if (left != 0 && right != 0)
            ans = min(ans, c[left] + c[j] + c[right]);
    }
    if (ans == 1e9)
        puts("-1");
    else
        printf("%d\n", ans);
    return 0;
}