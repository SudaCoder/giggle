#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--) {
		int n,k;
		cin>>n>>k;
		while(n>1&&k) {
			n=(n+1)/2;
			k--;
		}
		cout<<n<<endl;
	} 
	return 0;
}
