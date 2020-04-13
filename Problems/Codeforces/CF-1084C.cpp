//1084C
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

int n;
char s[N];
vector<int> v;
long long ans;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != 'a' && s[i] != 'b') continue;
        if (s[i] == 'a') t++;
        else {
            if (t != 0) v.push_back(t);
            t = 0;
        }
    }
    if (t != 0) v.push_back(t);
    ans = 1;
    for (int i = 0; i < v.size(); ++i) {
        ans = (ans * (v[i] + 1)) % mod;
    }
    ans = (ans + mod - 1) % mod;
    printf("%lld\n", ans);
    return 0;
}