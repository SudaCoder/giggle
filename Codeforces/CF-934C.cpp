/**
 * update by wrj
 **/ 

#include <iostream>
#include <vector>
const int N = 2e3+9;

using namespace std;
int n, dp[5][N], a[N], b[5]={0,1,2,1,2}; 

int main () {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]+(a[j]==b[i]));
    }
  }
  printf("%d\n", dp[4][n]);
  return 0;