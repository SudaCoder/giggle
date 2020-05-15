// 716B
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int cnt[30], num, n, flag;
char s[N];

void gao() {
  for (int i = 0; i < N; ++i)
    if (s[i] == '?')
      s[i] = 'A';
}

void deal(int l, int r) {
  for (int i = l; i <= r; ++i) {
    if (s[i] == '?') {
      for (int c = 0; c < 26; ++c) {
        if (cnt[c] == 0) {
          cnt[c] = 1;
          s[i] = 'A' + c;
          break;
        }
      }
    }
  }
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  if (n < 26) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < 26; ++i) {
    if (s[i] == '?')
      continue;
    cnt[s[i] - 'A']++;
    if (cnt[s[i] - 'A'] == 2)
      num++;
  }
  if (num == 0) {
    flag = 1;
    deal(0, 25);
  }
  for (int i = 26; i < n; ++i) {
    if (flag)
      break;
    if (s[i - 26] != '?') {
      cnt[s[i - 26] - 'A']--;
      if (cnt[s[i - 26] - 'A'] == 1)
        num--;
    }
    if (s[i] != '?') {
      cnt[s[i] - 'A']++;
      if (cnt[s[i] - 'A'] == 2)
        num++;
    }
    if (num == 0) {
      flag = 1;
      deal(i - 25, i);
    }
  }
  if (flag) {
    gao();
    printf("%s\n", s);
  } else {
    puts("-1");
  }
  return 0;
}