//1047B
#include <bits/stdc++.h>
using namespace std;

int n, x, y, ans;

int main() {
    cin >> n;
    while (n--) {
        cin >> x >> y;
        ans = max(ans, x + y);
    }
    cout << ans << endl;
    return 0;
}