
#include <bits/stdc++.h>
#include "bitmap_image.hpp"

#define RAD(x) (((x)*PI)/180.0)
#define NEX(x) ((x)==2?0:(x)+1)
#define INF 10
#define EPS 1e-10

using namespace std;

const double PI=acos(-1.0);
const double z_max=1.0;
int n;

struct Point
{
    double x,y,z;
    Point(){}
    Point(double a,double b,double c)
    {
        x=a,y=b,z=c;
    }
};



struct Triangle {
    double x[3],y[3],z[3];
    int color[3];
    Triangle() {}

    Triangle(double a[3],double b[3],double c[3],int red,int green,int blue) {

        for(int i=0;i<3;i++)x[i]=a[i];
        for(int i=0;i<3;i++)y[i]=b[i];

        for(int i=0;i<3;i++)z[i]=c[i];
        color[0]=red;
        color[1]=green;
        color[2]=blue;
    }
};

double dx,dy,zBuffer[1000][1000];
vector<Triangle>unpo;
int color[1000][1000][3],screenW,screenH,x_left,y_left,z_front,z_far;

double top_y,left_x;

void scanline(Triangle t)
{



}


void apply_procedure(void)
{
    for(int i=0;i<n;i++){
        scan(unpo[i]);


    }


}

int main() {
    int i,j,red,green,blue;
    double x[3],y[3],z[3];
    screenW=1000,screenH=1000,x_left=-1,y_left=-1,z_front=0,z_far=1;

    dx=2.0/screenW;
    dy=2.0/screenH;

    top_y=1-dy/2.0;
    left_x=-1+dx/2.0;



    freopen("input.txt","rb",stdin);
    freopen("zbuffer.txt","wb",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int i=0;i<3;i++){
            cin>>x[i]>>y[i]>>z[i];
            x[i]+=1;
            y[i]+=1;
            z[i]+=1;
        }


        Triangle t=Triangle(x,y,z,(10*i)%255,0,(50*i)%255);
        unpo.push_back(t);
    }
        //cout<<endl;



    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++)zBuffer[i][j]=10.0;
    }

    apply_procedure();





    bitmap_image image(screenW,screenH);
    for(i=0;i<screenH;i++){
        for(j=0;j<screenW;j++){
            image.set_pixel(j,screenH-i-1,color[i][j][0],color[i][j][1],color[i][j][2]);
        }
    }
    image.save_image("1.bmp");


    return 0;
}





