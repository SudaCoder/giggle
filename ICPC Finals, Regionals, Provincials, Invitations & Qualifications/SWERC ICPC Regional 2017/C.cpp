#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long LL;
const LL mod=1e9;
const int maxn=(1<<8)+7;
struct Matrix
{
	LL n,m;
	LL a[maxn][maxn];

    Matrix()
	{
		n=m=0;
		memset(a,0,sizeof(a));
	}
	Matrix(LL x,LL y)
	{
		n=x,m=y;
		memset(a,0,sizeof(a));
	}

	void clear()
	{
		n=m=0;
		memset(a,0,sizeof(a));
	}
	void iden()
	{
	    memset(a,0,sizeof(a));
	    for(int i=0;i<n;i++)
            a[i][i]=1;

	}

	Matrix operator *(const Matrix &b)const
	{
		Matrix tmp;
		tmp.clear();
		tmp.n=n;tmp.m=b.m;
		for(LL i=0;i<n;++i)
			for(LL j=0;j<b.m;++j)
				for(LL k=0;k<m;++k)
					tmp.a[i][j]=(tmp.a[i][j]+((a[i][k])*(b.a[k][j]))%mod+mod)%mod;
		return tmp;
	}
}A,B;

int p[9]={1,1,2,3,5,8,13,21,34};

int main()
{
    LL n,m;
    scanf("%lld%lld",&n,&m);
    LL nn=1<<n;
	B.n = B.m = A.n = A.m = nn;
    for(int s=0;s<nn;s++)
    {
        for(int e=0;e<nn;e++)
        {
            int cnt=0;
            LL temp=1;
            for(int i=0;i<n;i++)
            {
                int k=((s>>i)&1)+((e>>i)&1);
                if(k==2)
                    temp=0;
                else if(k==1)
                {
                    temp=temp*p[cnt]%mod;
                    cnt=0;
                }
                else cnt++;
            }
            temp=temp*p[cnt]%mod;
            A.a[s][e]=temp;
            //printf("%lld ",A.a[s][e]);
        }
        //printf("\n");
    }
    B.iden();
    while(m)
    {
        if(m&1)
            B=B*A;
        m>>=1;
        A=A*A;
    }
    printf("%lld\n",B.a[0][0]);
    return 0;
}
