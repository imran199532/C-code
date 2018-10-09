#include<bits/stdc++.h>
#include<glut.h>
using namespace std;
#define ll long long
#define mx 100010
#define pi pair<int,int>
#define mp make_pair
#define ss second
#define ff first
#define pb push_back
#include <windows.h>
#include <gl/gl.h>

struct Point;
pi first;
int orien(Point x,Point y,Point z);
int dist(Point p1,Point p2);


struct Point
{
    int x;
    int y;

    Point(){};
    Point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    bool operator< ( const Point &p)const

    {
        if(x==first.ff && y==first.ss)return 1;
        Point fst=Point(first.ff,first.ss);
       // int ori=orien(fst,Point(x,y),p);
       int val=(y-fst.y)*(p.x-fst.x)-(x-fst.x)*(p.y-fst.y);
       if(val<0)return 1;
       if(val>0)return 0;

        if(dist(fst,p)<=dist(fst,Point(x,y)))return 0;
        return 1;
    }


};

//Point first;


int orien(Point p, Point q,Point r)
{
    int val=(q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if(val==0)return 0;
    if(val>0)return 1;
    return 2;
}

int dist(Point p,Point q)
{
    return pow(p.x-q.x,2)+pow(p.y-q.y,2);
}

/*
int compare(const void *pp1,const void *pp2)
{
    pi *p1=(pi*)pp1,*p2=(pi*)pp2;
    int ori=orien(first,*p1,*p2);
    if(ori==0){
        if(dist(first,*p2)>=dist(first,*p1))return -1;
        return 1;
    }
    if(ori==2)return -1;
    return 1;
}

*/

Point topNext(stack<Point> &stk)
{
    Point po = stk.top();
    stk.pop();
    Point res = stk.top();
    stk.push(po);
    return res;
}
/*
bool cmp(pi p1, pi p2)
{
    cout<<"K";
   // return 1;

    int ori=orien(first,p1,p2);
    if(ori==0){
        if(dist(first,p2)>=dist(first,p1))return 0;
        return 1;
    }
    if(ori==2)return 0;
    return 1;

}*/

double convex(vector<Point> points,int n)
{
    int my=points[0].y,mn=0;

    for(int i=1;i<n;i++){
        int y=points[i].y;
        if(y<my ||(y==my && points[i].x<points[mn].x)){
            mn=i;
            my=y;
        }
    }

    swap(points[mn],points[0]);
    first=mp(points[0].x,points[0].y);

    sort(points.begin(),points.end());

    for(int i=0;i<n;i++){
        cout<<points[i].x<<" "<<points[i].y<<endl;
    }

    stack<Point>stk;
    stk.push(points[0]);
    stk.push(points[1]);
    stk.push(points[2]);
    //stk.push(points[2]);

    for(int i=3;i<n;i++){
        while(orien(topNext(stk),stk.top(),points[i])!=2){
            stk.pop();
        }
        stk.push(points[i]);
    }

    Point cur;
    cur=stk.top();
    Point initial=cur;
    double distance=0;
    while(!stk.empty())
    {
        Point po=stk.top();
        stk.pop();
        distance+=pow(dist(cur,po),0.5);
        cur=po;

    }

    distance+=pow(dist(cur,initial),0.5);
    return distance;



}


int main()
{

    freopen("C:/Users/imran/Desktop/input.txt","rb",stdin);
   // freopen("output.txt","w",stdout);
    vector<Point>points;
   //pi points[1232];

    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        points.pb(Point(x,y));
        //points[i]=mp(x,y);
    }

    cout<<convex(points,n);



    fclose(stdin);


}

