#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
#define pi pair<int,int>
#define mp make_pair
#define ss second
#define ff first
#define pb push_back


int orien(pi p, pi q,pi r)
{
    int val=(q.ss - p.ss) * (r.ff - q.ff) - (q.ff - p.ff) * (r.ss - q.ss);

    if(val==0)return 0;
    if(val>0)return 1;
    return 2;
}

int dist(pi p,pi q)
{
    return pow(p.ff-q.ff,2)+pow(p.ss-q.ss,2);
}


int compare(pi first,const void *pp1,const void *pp2)
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



pi topNext(stack<pi> &stk)
{
    pi po = stk.top();
    stk.pop();
    pi res = stk.top();
    stk.push(po);
    return res;
}

double convex(vector<pi>points,int n)
{
    int my=points[0].ss,mn=0;

    for(int i=1;i<n;i++){
        int y=points[i].ss;
        if(y<my ||(y==my && points[i].ss<points[mn].ss)){
            mn=i;
            my=points[i].ss;
        }
    }

    swap(points[mn],points[0]);
    pi first=points[0];
    cout<<&points[1]<<endl;
    //qsort(&points[1],n-1,sizeof(pi),compare);

    stack<pi>stk;
    stk.push(points[0]);
    stk.push(points[1]);
    stk.push(points[2]);

    for(int i=2;i<n;i++){
        while(orien(topNext(stk),stk.top(),points[i])!=2){
            stk.pop();
        }
        stk.push(points[i]);
    }

    pi cur;
    cur=stk.top();
    first=cur;
    double distance=0;
    while(!stk.empty())
    {
        pi po=stk.top();
        stk.pop();
        distance+=pow(dist(cur,po),0.5);
        cur=po;

    }

    distance+=pow(dist(cur,first),0.5);
    return distance;



}


int main()
{

    freopen("C:/Users/imran/Desktop/input.txt","rb",stdin);
   // freopen("output.txt","w",stdout);
    vector<pi>points;

    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        points.pb(mp(x,y));
    }

    cout<<convex(points,n);



    fclose(stdin);
    //fclose(stdout);

}

