#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL dp[205][205];
LL C[205][205];
const LL mod=998244353;
string s,t;
int main() {
	int T;
	cin>>T;
	C[0][0]=1;
	for(int i=1;i<=200;i++) {
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	while(T--) {
		int n,k,m;
		cin>>n>>k>>m;
		cin>>s>>t;
		int cnt=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
			cnt+=(s[i]==t[i]);
		dp[cnt][0]=1;
		for(int i=1;i<=k;i++) {
			for(int j=0;j<=n;j++) {
				for(int t=0;t<=m;t++)
					if(j+m-2*t>=0&&j+m-2*t<=n)
						dp[j+m-2*t][i]=(dp[j+m-2*t][i]+dp[j][i-1]*C[j][t]%mod*C[n-j][m-t]%mod)%mod;
			}
		}
		cout<<dp[n][k]<<endl;
	}
	return 0;
}
