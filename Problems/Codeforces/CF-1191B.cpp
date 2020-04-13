// 1191B
#include <bits/stdc++.h>
using namespace std;

int id[256];
int cnt[3][12];
char s[3][4];

int main() {
    id['m'] = 0;
    id['p'] = 1;
    id['s'] = 2;
    scanf("%s%s%s", s[0], s[1], s[2]);
    cnt[id[s[0][1]]][s[0][0] - '0']++;
    cnt[id[s[1][1]]][s[1][0] - '0']++;
    cnt[id[s[2][1]]][s[2][0] - '0']++;
    int ans = 2;
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= 9; ++j) {
            ans = min(ans, 3 - cnt[i][j]);
            if (j + 2 <= 9) {
                ans = min(ans, 3 - !!cnt[i][j] - !!cnt[i][j + 1] - !!cnt[i][j + 2]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}