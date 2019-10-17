#include<bits/stdc++.h>
using namespace std;
using LL = long long;
string cel[5]={"Monday",
"Tuesday",
"Wednesday",
"Thursday",
"Friday"};
int main()
{
	int t;
	cin>>t;
	while(t--) {
		int y1,m1,d1,y2,m2,d2;
		string s;
		cin>>y1>>m1>>d1>>s>>y2>>m2>>d2;
		LL sum1=y1*12*360ll+m1*30+d1;
		LL sum2=y2*12*360ll+m2*30+d2;
		LL p;
		for(int i=0;i<5;i++)
			if(cel[i]==s)
				p=i;
		p+=sum2-sum1;
		p%=5;
		if(p<0) p+=5;
		cout<<cel[p]<<endl;
	}
	return 0;
}
