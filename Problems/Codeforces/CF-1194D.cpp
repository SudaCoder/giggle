#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int Tcase = 0;

int main() {
  scanf("%d", &Tcase);
  while (Tcase--) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k % 3) {
      if (n % 3)
        puts("Alice");
      else
        puts("Bob");
    } else {
      n %= k + 1;
      if (n == k || n % 3)
        puts("Alice");
      else
        puts("Bob");
    }
  }
}
