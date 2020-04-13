#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 1e5 + 9;
using namespace std;
const int mod = 1e9 + 7;
char s[N];
int dp[N], n;

int main() {
    dp[0] = 1;
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i++) {
        if (s[i] == 'n' || s[i] == 'u') {
            if (s[i] == s[i - 1]) {
                dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
            } else
                dp[i] = dp[i - 1];
        } else if (s[i] == 'm' || s[i] == 'w') {
            dp[i] = 0;
        } else
            dp[i] = dp[i - 1];
    }
    return printf("%d\n", dp[len]), 0;
}