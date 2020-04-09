//799C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, c, d, ans;
int pre[N];
int cntc, cntd;
struct node {
    int b, p;
    bool operator<(const node &rhs) const {
        return p < rhs.p;
    }
}coin[N], diamond[N];

char op[3];

int main() {
    scanf("%d%d%d", &n, &c, &d);
    for (int i = 1; i <= n; ++i) {
        int b, p;
        char op[3];
        scanf("%d%d%s", &b, &p, op);
        if (op[0] == 'C') {
            ++cntc;
            coin[cntc].b = b;
            coin[cntc].p = p;
        }
        else {
            ++cntd;
            diamond[cntd].b = b;
            diamond[cntd].p = p;
        }
    }
    sort(coin + 1, coin + cntc + 1);
    sort(diamond + 1, diamond + cntd + 1);
    int i = 1, j = cntc;
    for (int k = 1; k <= cntc; ++k) pre[k] = max(pre[k - 1], coin[k].b);
    while (j >= 2 && coin[1].p + coin[j].p > c) j--;
    while (j >= 2) {
        while (i < cntc && coin[j].p + coin[i + 1].p <= c) {
            i++;
        }
        ans = max(ans, coin[j].b + pre[min(i, j - 1)]);
        j--;
    }
    i = 1, j = cntd;
    for (int k = 1; k <= cntd; ++k) pre[k] = max(pre[k - 1], diamond[k].b);
    while (j >= 2 && diamond[1].p + diamond[j].p > d) j--;
    while (j >= 2) {
        while (i < cntd && diamond[j].p + diamond[i + 1].p <= d) {
            i++;
        }
        ans = max(ans, diamond[j].b + pre[min(i, j - 1)]);
        j--;
    }
    int mx = 0;
    for (int i = 1; i <= cntc; ++i) {
        if (coin[i].p <= c)
            mx = max(mx, coin[i].b);
    }
    if (mx != 0) {
        for (int i = 1; i <= cntd; ++i) {
            if (diamond[i].p <= d)
                ans = max(ans, mx + diamond[i].b);
        }
    }
    printf("%d\n", ans);
    return 0;
}