// 1157B
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

char s[N];
int f[12], n;

int main() {
  scanf("%d%s", &n, s);
  for (int i = 1; i <= 9; ++i)
    scanf("%d", &f[i]);
  for (int i = 0; i < n; ++i) {
    int x = s[i] - '0';
    if (f[x] > x) {
      s[i] = '0' + f[x];
      for (int j = i + 1; j < n; ++j) {
        int x = s[j] - '0';
        if (f[x] >= x)
          s[j] = '0' + f[x];
        else
          break;
      }
      break;
    }
  }
  printf("%s\n", s);
  return 0;
}