#include <bits/stdc++.h>
#include "bitmap_image.hpp"

#define RAD(x) (((x)*PI)/180.0)
#define NEX(x) ((x)==2?0:(x)+1)
#define INF 10
#define EPS 1e-10

using namespace std;

const double PI=acos(-1.0);

double screen__width=1000,scree_height=1000,x_limit=-1,y_limit=-1,z_limit=1;

struct Point
{
    double x,y,z;
    Point(){};
    Point(double p,double q,double r)
    {
        x=p,y=q,z=r;
    }
};


struct Triangle {
    double x[3],y[3],z[3];
    int colorComponent[3];
    Triangle() {}
    Triangle(const Triangle &t) {
        int i;
        for(i=0;i<3;i++) {
            x[i]=t.x[i];
            y[i]=t.y[i];
            z[i]=t.z[i];
            colorComponent[i]=t.colorComponent[i];
        }
    }
    Triangle(Point a,Point b,Point c,int red,int green,int blue) {
        x[0]=a.a[0][0]; y[0]=a.a[1][0]; z[0]=a.a[2][0];
        x[1]=b.a[0][0]; y[1]=b.a[1][0]; z[1]=b.a[2][0];
        x[2]=c.a[0][0]; y[2]=c.a[1][0]; z[2]=c.a[2][0];

        colorComponent[0]=red;
        colorComponent[1]=green;
        colorComponent[2]=blue;
    }
};


int main()
{
     freopen("stage3.txt","rb",stdin);
     double x,y,z;

     int n;
     cin>>n;
     for(int i=0;i<n;i++){
        cin>>x>>y>>z;
        Point a=Point(x,y,z);

        cin>>x>>y>>z;
        Point b=Point(x,y,z);

        cin>>x>>y>>z;
        Point c=Point(x,y,z);

        Triangle tr=Triangle(a,b,c,0,0,0);

     }
}
