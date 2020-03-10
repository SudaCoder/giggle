//CF1073B
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N], b[N], pos[N], mx;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        cout << max(0, pos[b[i]] - mx) << " ";
        mx = max(mx, pos[b[i]]);
    }
    cout << endl;
    return 0;
}