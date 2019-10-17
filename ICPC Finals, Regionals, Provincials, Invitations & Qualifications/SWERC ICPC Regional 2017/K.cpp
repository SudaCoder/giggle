#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
const int maxn=2e5+7;
int n,r;
int sgn(double x)
{
    if(fabs(x)<eps)
        return 0;
    else if(x<0)
        return -1;
    else return 1;
}

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
    Point operator -(const Point &rhs) const
    {
        return Point(x-rhs.x,y-rhs.y);
    }
    double cross(const Point &rhs) const
    {
        return x*rhs.y-y*rhs.x;
    }
    double dis(const Point &rhs) const
    {
        return hypot(x-rhs.x,y-rhs.y);
    }
}point[maxn],vertex[maxn];

bool cmp_x(const Point &a,const Point &b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
int Andrew()
{
    sort(point,point+n,cmp_x);
    int k=0;
    for(int i=0;i<n;i++)
    {
        while(k>1&&(vertex[k-1]-vertex[k-2]).cross
        (point[i]-vertex[k-1])<=0) k--;
        vertex[k++]=point[i];
    }
    int m=k;
    for(int i=n-2;i>=0;i--)
    {
        while(k>m&&(vertex[k-1]-vertex[k-2]).cross
        (point[i]-vertex[k-1])<=0) k--;
        vertex[k++]=point[i];
    }
    if(k>1) k--;
    return k;
}

double get_hight(Point a,Point b,Point c)
{
    double d1=a.dis(b);
    double d2=(b-a).cross(c-a);
    return fabs(d2/d1);
}

double get_min_width(int k)
{
    vertex[k]=vertex[0];
    if(k<=2)
        return 0;
    double res=2.0*r;
    int u=2;
    for(int i=0;i<k;i++)
    {
        Point temp=vertex[i+1]-vertex[i];
        while((vertex[u+1]-vertex[i]).cross(temp)
              -(vertex[u]-vertex[i]).cross(temp)<=0)
                u=(u+1)%k;
        res=min(res,get_hight(vertex[i],vertex[i+1],vertex[u]));
    }
    return res;
}

int main()
{
    scanf("%d%d",&n,&r);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",&point[i].x,&point[i].y);
    printf("%.16f",get_min_width(Andrew()));
    return 0;
}
