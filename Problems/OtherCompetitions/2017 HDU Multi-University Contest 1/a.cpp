#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, cas = 0;
    const double s = log10(2);
    while (~scanf("%d", &a)) {
        printf("Case #%d: %d\n", ++cas, (int)(a * s));
    }
    return 0;
}