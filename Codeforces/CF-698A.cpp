#include <iostream>
#include <cstring>
#include <cstdio>
const int maxn = 1e4;
int a[maxn];
int dp[maxn][3];
const int inf = 1e9;
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        if(a[i]==0){
            dp[i][1] = -inf;
            dp[i][2] = -inf;
        }else if(a[i]==1){
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
            dp[i][2] = -inf;
        }else if(a[i]==2){
            dp[i][1] = -inf;
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
        }else{
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
        }
    }
    printf("%d\n",n-max(max(0, dp[n][0]), max(dp[n][1], dp[n][2])));
}