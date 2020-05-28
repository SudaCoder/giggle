//1187B
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

char s[N], t[N];
int cnt[N][26];
int now[26];
int n, m, len;

bool check(int mid) {
    for (int i = 0; i < 26; ++i) {
        if (now[i] > cnt[mid][i])
            return false;
    }
    return true;
}

int main() {
    scanf("%d%s%d", &n, s + 1, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j)
            cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'a']++;
    }
    while (m--) {
        scanf("%s", t + 1);
        memset(now, 0, sizeof(now));
        len = strlen(t + 1);
        for (int i = 1; i <= len; ++i)
            now[t[i] - 'a']++;
        int l = len, r = n, ans;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}