#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[3];
int b[3];
LL ans[3];
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[i%3]+=x;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        b[i%3]+=x;
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
           ans[(i+j)%3]+=1ll*a[i]*b[j];
    printf("%lld %lld %lld\n",ans[0],ans[1],ans[2]);
    return 0;
}
