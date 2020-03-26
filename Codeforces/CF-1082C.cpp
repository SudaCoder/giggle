//1082C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;

int s[N], r[N], cnt[N], mx;
int sum[N], ans;
vector<int> v[N];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &s[i], &r[i]);
        v[s[i]].push_back(r[i]);
    }
    for (int i = 1; i <= m; ++i) {
        sort(v[i].begin(), v[i].end(), cmp);
        int tmp = 0;
        for (int j = 0; j < v[i].size(); ++j) {
            tmp += v[i][j];
            if (tmp <= 0) break;
            sum[j + 1] += tmp;
        }
    }
    for (int i = 1; i <= n; ++i) 
        ans = max(ans, sum[i]);
    printf("%d\n", ans);
    return 0;
}