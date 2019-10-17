#include<bits/stdc++.h>
using namespace std;
long long dp[105][2];
int main() {
    int l,k;
    cin>>l>>k;
    long long ans=0;
    dp[0][0]=1;
    for(int i=0;i<=l;i++) {
        dp[i+1][1]+=dp[i][0];
        dp[i+k][1]+=dp[i][0];
        dp[i+1][0]+=dp[i][1];
        ans+=dp[i][1];
    }
    cout<<ans<<endl;
    return 0;
}
