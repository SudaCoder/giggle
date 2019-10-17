#include<cstdio>
#include<map>
using namespace std;
typedef long long LL;
map<LL,int> mp;
LL a[2005],b[2005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
          for(int i=0;i<m;i++)
            scanf("%lld",&b[i]);
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(b[j]>=a[i])
                    mp[b[j]-a[i]]++;
         int cnt=-1;
          LL ans;
        for(auto it:mp)
            if(it.second>cnt)
             {
                cnt=it.second;
                ans=it.first;
            }
         printf("%lld\n",ans);
    return 0;
}
