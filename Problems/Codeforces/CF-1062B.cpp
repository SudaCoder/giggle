#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int n;

void solve(vector<pair<int, int>> p) {
    int cnt = 0, mx = 0, ans = 1, flag = 0;
    for (int i = 0; i < p.size(); i++) {
        ans = ans * p[i].first;
        if (i && p[i].second != p[i - 1].second) {
            flag = 1;
        }
        mx = max(mx, p[i].second);
    }
    while (mx > 1) {
        if (mx & 1) {
            mx++;
            flag = 1;
        }
        mx >>= 1;
        cnt++;
    }
    printf("%d %d\n", ans, cnt + flag);
}

int main() {
    vector<pair<int, int>> p;
    scanf("%d", &n);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            p.push_back(make_pair(i, cnt));
        }
    }
    if (n > 1)
        p.push_back(make_pair(n, 1));
    solve(p);
    return 0;
}