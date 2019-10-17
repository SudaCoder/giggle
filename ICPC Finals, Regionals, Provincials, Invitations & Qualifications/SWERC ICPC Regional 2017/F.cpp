#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w,n,a,b;
    int sum=0;
    scanf("%d%d",&w,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        sum+=a*b;
    }
    printf("%d\n",sum/w);
    return 0;
}
