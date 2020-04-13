//998B
#include <bits/stdc++.h>
using namespace std;

int n, B, a[110], ans;
int cnt, now;
vector<int> v;

int main() {
    scanf("%d%d", &n, &B);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2 == 0)
            cnt++;
        else
            cnt--;
        if (cnt == 0 && i != n) {
            v.push_back(abs(a[i] - a[i + 1]));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if (now + v[i] <= B) {
            ans++;
            now += v[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}