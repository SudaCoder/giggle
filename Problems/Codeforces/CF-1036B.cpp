#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;

ll n, m, k;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &m, &k);
        if (n < m)
            swap(n, m);
        if ((n & 1) != (m & 1)) {
            n--;
            k--;
        } else if ((n & 1) != (k & 1)) {
            n--;
            k -= 2;
        }
        printf("%lld\n", k < n ? -1 : k);
    }
    return 0;
}