#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

int n, cas, l, vis[26];
long long ans;
vector<int> g[26];
char s[N];

int main() {
    while (~scanf("%d", &n)) {
        ans = 0;
        for (int i = 0; i < 26; ++i) {
            g[i].clear();
            g[i].resize(N);
            vis[i] = 0;
        }
        while (n--) {
            scanf("%s", s);
            l = strlen(s);
            for (int i = 0; i < l; ++i)
                g[s[i] - 'a'][l - i - 1]++;
            if (l != 1)
                vis[s[0] - 'a'] = 1;
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < N - 1; ++j) {
                g[i][j + 1] += g[i][j] / 26;
                g[i][j] %= 26;
            }
            reverse(g[i].begin(), g[i].end());
        }
        int zero = -1;
        for (int i = 0; i < 26; ++i)
            if (!vis[i]) {
                if (zero == -1 || g[i] < g[zero])
                    zero = i;
            }
        swap(g[0], g[zero]);
        sort(g + 1, g + 26);
        for (int i = 1; i < 26; ++i)
            reverse(g[i].begin(), g[i].end());
        for (int i = 1; i < 26; ++i) {
            long long base = i;
            for (int j = 0; j < N; ++j) {
                ans = (ans + base * g[i][j]) % mod;
                base = base * 26 % mod;
            }
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}