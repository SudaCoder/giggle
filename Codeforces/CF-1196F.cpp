#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

const int N = 2e5+9;
#define ll long long
using namespace std;

struct Edge {
    int u, v, w;
} e[N];

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int n, m, k, p[N<<1];
ll mp[888][888];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    sort(e, e+m, cmp);
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        p[cnt++] = e[i].u;
        p[cnt++] = e[i].v;
    }
    sort(p, p+cnt);
    cnt = unique(p, p+cnt) - p;
    memset(mp, 0x3f, sizeof mp);
    for (int i = 0; i < k; i++) {
        int u = lower_bound(p, p+cnt, e[i].u) - p;
        int v = lower_bound(p, p+cnt, e[i].v) - p;
        mp[u][v] = e[i].w;
        mp[v][u] = e[i].w;
    }
    for (int k = 0; k < cnt; k++) {
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    vector<ll> ew;
    for (int i = 0; i < cnt; i++) {
        for (int j = i+1; j < cnt; j++) {
            ew.push_back(mp[i][j]);
        }
    }
    sort(ew.begin(), ew.end());
    printf("%lld\n", ew[k-1]);
    return 0;
}