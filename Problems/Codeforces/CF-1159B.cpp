#include <cstdio>
#include <iostream>

using namespace std;
int n, x;

int main() {
    scanf("%d", &n);
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        ans = min(ans, x / max(i - 1, n - i));
    }
    printf("%d\n", ans);
    return 0;
}