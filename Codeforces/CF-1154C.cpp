//1154C
#include <bits/stdc++.h>
using namespace std;

int a[3], n = 1e9, ans;
int eat[7] = {0, 0, 1, 2, 0, 2, 1};

int gao(int start) {
    int ret = 0;
    for (int i = start; i < start + 7; ++i) {
        if (a[eat[i % 7]] != 0) {
            a[eat[i % 7]]--;
            ret++;
        }
        else {
            for (int j = start; j < i; ++j) {
                a[eat[j % 7]]++;
            }
            break;
        }
    }
    return ret;
}

int main() {
    cin >> a[0] >> a[1] >> a[2];
    n = min(n, a[0] / 3);
    n = min(n, a[1] / 2);
    n = min(n, a[2] / 2);
    a[0] -= 3 * n;
    a[1] -= 2 * n;
    a[2] -= 2 * n;
    for (int i = 0; i < 7; ++i)
        ans = max(ans, gao(i));
    ans += 7 * n;
    cout << ans << endl;
    return 0;
}