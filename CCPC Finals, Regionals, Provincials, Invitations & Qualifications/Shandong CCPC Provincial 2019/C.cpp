#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=1e5+7;
LL x[maxn],y[maxn];
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		string s;
		cin>>n>>k;
		cin>>s;
		LL ans=0;
		for(int i=0;i<n;i++) {
			x[i+1]=x[i];
			y[i+1]=y[i];
			if(s[i]=='U') y[i+1]=y[i]+1;
			else if(s[i]=='D') y[i+1]=y[i]-1;
			else if(s[i]=='L') x[i+1]=x[i]-1;
			else if(s[i]=='R') x[i+1]=x[i]+1;
			//cout<<x[i+1]<<" "<<y[i+1]<<endl;
			ans=max(ans,abs(x[i+1])+abs(y[i+1]));
		}
		for(int i=0;i<n;i++) {
			ans=max(ans,abs(x[i+1]+(k-1)*x[n])+abs(y[i+1]+(k-1)*y[n]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
