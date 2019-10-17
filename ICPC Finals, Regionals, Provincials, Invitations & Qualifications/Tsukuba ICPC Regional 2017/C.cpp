#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,t,h;
    scanf("%d%d",&n,&t);
    long long b=0,j=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&h);
        b+=h;
        j=max(j,1ll*h);
        if(b>t) printf("%lld\n",1);
        else printf("%lld\n",2+(t-b)/j);
    }
    return 0;
}
