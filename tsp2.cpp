#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
#define pi pair<double,double>
#define mp make_pair
#define ss second
#define ff first
#define pb push_back

vector<pi>vec;

int vis[mx];

double cost_cal(int i,int j)
{
    double x1=vec[i].ff,x2=vec[j].ff;
    double y1=vec[i].ss,y2=vec[j].ss;

    double cs=pow(x1-x2,2)+pow(y1-y2,2);
    double cost=(double)pow(cs,0.5);
    return cost;
}

double min1(int i)
{
    double mn=10000000000;
    for(int j=0;j<vec.size();j++){
        if(i==j)continue;
        mn=min(mn,cost_cal(i,j));
    }
    return mn;
}

int min2(int i)
{
    double mn1=10000000000,mn2=10000000000;
    for(int j=0;j<vec.size();j++){
        if(i==j)continue;
        double cost=cost_cal(i,j);
        if(cost<=mn1){
            mn2=mn1;
            mn1=cost;
        }

        else if(cost<=mn2 && cost!=mn1)mn2=cost;
    }
    return mn2;
}

void calc_cost(vector<int>a,double &mn_cost,vector<int>&ans)
{
    double cost=0.0;
    int n=a.size();
    for(int i=0;i<a.size();i++){
        double x1=vec[a[i]].ff,x2=vec[a[(i+1)%n]].ff;
        double y1=vec[a[i]].ss,y2=vec[a[(i+1)%n]].ss;

        double cs=pow(x1-x2,2)+pow(y1-y2,2);
        cost+=(double)pow(cs,0.5);


    }

    if(cost<mn_cost){
        mn_cost=cost;
        ans=a;
    }
}

bool valid(vector<int>a,int i,int j)
{

    double x1=vec[a[i]].ff,x2=vec[a[j]].ff;
    double y1=vec[a[i]].ss,y2=vec[a[j]].ss;
    for(int k=0;k<i;k++){
        double x3=vec[a[k]].ff,y3=vec[a[k]].ss;
        if((y3-y1)*1.0/(x3-x1)==(y1-y2)*1.0/(x1-x2))return 0;
    }



    return 1;

}

void tsp_next(vector<int>path,int n,int low_bound,int weight,int lev,double &mn_cost,vector<int>&ans)
{

    if(lev==n){
        double cur_cost=weight+cost_cal(path[n-1],path[0]);
        if(cur_cost<mn_cost){
            mn_cost=cur_cost;
            ans=path;
        }
        return;

    }

    for(int i=0;i<n;i++){
        if(path[lev-1]!=i && vis[i]==0 && valid(path,lev-1,i) )
        {
            int temp=low_bound;
            weight+=cost_cal(path[lev-1],i);
            if(lev==1){
                low_bound=(min1(path[lev-1])+min1(i))*1.0/2;

            }
            else low_bound=(min2(path[lev-1])+min1(i))*1.0/2;

            if(weight+low_bound<mn_cost){

                path[lev]=i;
                vis[i]=true;
                tsp_next(path,n,low_bound,weight,lev+1,mn_cost,ans);

            }
            weight-=cost_cal(path[lev-1],i);
            low_bound=temp;
            for(int k=0;k<n;k++)vis[k]=0;
            for(int k=0;k<lev;k++)vis[path[k]]=1;
        }

    }



}

void tsp(vector<int>path,int n,double &mn_cost,vector<int>&ans)
{
    double low_bound=0;
    for(int i=0;i<n;i++)low_bound+=(min1(i)+min2(i));
    vis[0]=1;
    path[0]=0;
    for(int i=0;i<n;i++)path[i]=0;

    tsp_next(path,n,low_bound,0,1,mn_cost,ans);




}

int main()
{

    freopen("C:/Users/imran/Desktop/input1.txt","rb",stdin);
    freopen("output2.txt","w",stdout);

    int ct,n,t;
    double x,y;
    cin>>ct;
    t=0;
    while(ct--)
    {
        vec.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            vec.pb(mp(x,y));
        }

        vector<int>path,ans;
        for(int i=0;i<n;i++)path.pb(i);

        double mn_cost=1000000000;

        tsp(path,n,mn_cost,ans);


        cout<<"Test Case "<<++t<<" : "<<mn_cost<<endl;

        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" -> ";

        cout<<'0'<<endl<<endl;


    }



    fclose(stdin);
    fclose(stdout);

}

