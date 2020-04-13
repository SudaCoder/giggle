//1084B
#include <bits/stdc++.h>
using namespace std;

long long n, s, v[1010], mn = 1e18, sum;

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        sum += v[i];
        mn = min(mn, v[i]);
    }
    s -= sum - mn * n;
    if (s <= 0) {
        cout << mn << endl;
        return 0;
    }
    if (s > mn * n) {
        cout << -1 << endl;
        return 0;
    }
    cout << mn - ((s - 1) / n + 1) << endl;
    return 0;
}