#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
pair<double,double> getPos(int d,int l) {
    double deg=1.0*d/180*pi;
    return make_pair(l*(cos(deg)-sin(deg)*sqrt(3)/3)
                     ,l*sin(deg)*2*sqrt(3)/3);
}
string getABC(int d,int l) {
    pair<double,double> p=getPos(d,l);
    double x=fmod(p.first,2),y=fmod(p.second,2);
    if(x+y<1) return "ABC";
    else if(x+y<2) {
        if(y>1) return "ACD";
        else if(x>1) return "ABD";
        else return "BCD";
    } else if(x+y<3) {
        if(x<1) return "ABD";
        else if(y<1) return "ACD";
        else return "BCD";
    } else return "ABC";
}
string getACD(int d,int l) {
    pair<double,double> p=getPos(d,l);
    double x=fmod(p.first,2),y=fmod(p.second,2);
    if(x+y<1) return "ACD";
    else if(x+y<2) {
        if(y>1) return "ABD";
        else if(x>1) return "ABC";
        else return "BCD";
    } else if(x+y<3) {
        if(x<1) return "ABC";
        else if(y<1) return "ABD";
        else return "BCD";
    } else return "ACD";
}
string getADB(int d,int l) {
    pair<double,double> p=getPos(d,l);
    double x=fmod(p.first,2),y=fmod(p.second,2);
    if(x+y<1) return "ABD";
    else if(x+y<2) {
        if(y>1) return "ABC";
        else if(x>1) return "ACD";
        else return "BCD";
    } else if(x+y<3) {
        if(x<1) return "ACD";
        else if(y<1) return "ABC";
        else return "BCD";
    } else return "ABD";
}
int main() {
    string xy,f1,f2;
    int d,l;
    cin>>xy>>d>>l;
    if(xy=="BC") f1=getABC(d,l);
    else if(xy=="CD") f1=getACD(d,l);
    else f1=getADB(d,l);
    cin>>xy>>d>>l;
    if(xy=="BC") f2=getABC(d,l);
    else if(xy=="CD") f2=getACD(d,l);
    else f2=getADB(d,l);
    cout<<(f1==f2?"YES":"NO")<<endl;
    return 0;
}
