// 622B
#include <bits/stdc++.h>
using namespace std;

int h, m, a;

int main() {
  scanf("%d:%d%d", &h, &m, &a);
  m += a;
  h += m / 60;
  m %= 60;
  h %= 24;
  printf("%02d:%02d\n", h, m);
  return 0;
}