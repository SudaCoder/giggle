//776C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N], n, k;
map<long long, int> cnt;
vector<long long> ks;
long long ans;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &a[i]);
    if (k == 1) {
        ks.push_back(k);
    }
    else if (k == -1) {
        ks.push_back(-1);
        ks.push_back(1);
    }
    else {
        long long temp = 1;
        while (abs(temp) <= 100000000000000) {
            ks.push_back(temp);
            temp *= k;
        }
    }
    cnt[0] = 1;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        for (int j = 0;j < ks.size(); ++j) {
            if (cnt.count(sum - ks[j]))
                ans += cnt[sum - ks[j]];
        }
        cnt[sum]++;
    }
    printf("%lld\n", ans);
    return 0;
}