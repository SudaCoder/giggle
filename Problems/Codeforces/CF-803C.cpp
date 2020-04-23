//803C
#include <bits/stdc++.h>
using namespace std;

long long n, k;

int a[200010];
long long ans = 1;

vector<long long> fac; 

int main() {
    cin >> n >> k;
    if (k >= 200000 || n < k * (k + 1) / 2) {
        cout << -1 << endl;
        return 0;
    }
    long long base = k * (k + 1) / 2, i = 1;
    while (i * i <= n) {
        if (n % i == 0) {
            fac.push_back(i);
            if (i * i != n)
                fac.push_back(n / i);
        }
        i++;
    }
    for (int j = 0; j < fac.size(); ++j) {
        if (base <= n / fac[j])
            ans = max(ans, fac[j]);
    }
    for (int i = 1; i < k; ++i) {
        cout << i * ans << " ";
        n -= i * ans;
    }
    cout << n << endl;
    return 0;
}