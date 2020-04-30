//618C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, x;

struct point {
    int x, y, id;
    bool operator<(const point &rhs) const {
        if (x == rhs.x)
            return y < rhs.y;
        return x < rhs.x;
    }
} a[N];

bool oneline(int i, int j, int k) {
    return 1LL * (a[i].x - a[j].x) * (a[i].y - a[k].y) == 1LL * (a[i].x - a[k].x) * (a[i].y - a[j].y);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    x = 3;
    while (oneline(1, 2, x)) x++;
    printf("%d %d %d\n", a[1].id, a[2].id, a[x].id);
    return 0;
}