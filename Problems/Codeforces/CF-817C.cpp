// 817C
#include <bits/stdc++.h>
using namespace std;

int sum(long long x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

long long n, s, ans;

int main() {
    cin >> n >> s;
    for (long long i = s; i <= s + 200 && i <= n; ++i)
        if (i - sum(i) >= s)
            ans++;
    ans += n - min(s + 200, n);
    cout << ans << endl;
    return 0;
}