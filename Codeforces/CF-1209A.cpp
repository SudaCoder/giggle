#include <cstdio>
#include <iostream>
#include <algorithm>

const int N = 1e5+9;
using namespace std;
int n, a[N];
bool vis[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) { 
    scanf("%d", &a[i]);
  }
  sort(a, a+n);
  n = unique(a, a+n) - a;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int idx = -1;
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        if (vis[j] || vis[a[i]/j]) {
          idx = 0;
          break;
        }
      } 
    }
    if (idx == -1) {
      vis[a[i]] = 1;
      cnt ++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}