//631C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct node {
    int t, r;
} op[N];

int n, m, a[N], ans[N], mx;

vector<node> options;
deque<int> que;

int main() {
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &op[i].t, &op[i].r);
        while (!options.empty() && options.back().r <= op[i].r)
            options.pop_back();
        options.push_back(op[i]);
        mx = max(mx, op[i].r);
    }
    for (int i = mx + 1; i <= n; ++i)
        ans[i] = a[i];
    sort(a + 1, a + mx + 1);
    for (int i = 1; i <= mx; ++i)
        que.push_back(a[i]);
    int status = 0; //1 -> r = 1, 2 -> r = 2
    int last = mx;
    for (int i = 0; i < options.size(); ++i) {
        node p = options[i];
        for (int j = last; j >= p.r + 1; --j) {
            if (status == 2) {
                ans[j] = que.front();
                que.pop_front();
            }
            else {
                ans[j] = que.back();
                que.pop_back();
            }
        }
        status = p.t;
        last = p.r;
    }
    for (int j = last; j; --j) {
        if (status == 2) {
            ans[j] = que.front();
            que.pop_front();
        }
        else {
            ans[j] = que.back();
            que.pop_back();
        }
    }
    for (int i = 1; i <= n; ++i)
        printf("%d%c", ans[i], " \n"[i == n]);
    return 0;
}