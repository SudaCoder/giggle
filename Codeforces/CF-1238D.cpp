#include <cstdio>
#include <iostream>
#include <algorithm>

const int N = 3e5+9;
using namespace std;
char s[N];
int n;

int main() {
    scanf("%d\n%s", &n, s+1);
    long long ans = n * (n - 1LL) >> 1;
    for (int i = 0; i < 2; i++) {
        int cur = 1;
        for (int j = 2; j <= n; j++) {
            if (s[j] == s[j-1]) cur ++;
            else {
                ans -= cur - i;
                cur = 1;
            }
        }
        if (i^1) reverse(s+1, s+1+n);
    }
    printf("%lld\n", ans);
    return 0;
}