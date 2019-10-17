#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int k,n,m,u,v;
		scanf("%d%s%d%d",&k,s,&n,&m);
		for(int i=0;i<m;i++) {
			scanf("%d%d",&u,&v);
		}
		n=m-(n-1);
		n%=k;
		printf("%d\n",1+(s[n]=='1'));
	}
	return 0;
} 
