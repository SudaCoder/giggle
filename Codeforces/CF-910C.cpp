//910C
#include<bits/stdc++.h>
using namespace std;


char s[10];
int n;

int notzero[12], cnt[12], ten[10], ans;

int main() {
    ten[0] = 1;
    for (int i = 1; i < 8; ++i)
        ten[i] = 10 * ten[i - 1];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        int len = strlen(s);
        notzero[s[0] - 'a'] = 1;
        for (int j = 0; j < len; ++j)
            cnt[s[j] - 'a'] += ten[len - j - 1];
    }
    int zero = -1;
    for (int i = 0; i < 10; ++i) {
        if (notzero[i] == 0) {
            if (zero == -1 || cnt[i] > cnt[zero])
                zero = i;
        }
    }
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        if (zero != i)
            v.push_back(cnt[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 9; ++i) {
        ans += (9 - i) * v[i];
    }
    printf("%d\n", ans);
    return 0;
}