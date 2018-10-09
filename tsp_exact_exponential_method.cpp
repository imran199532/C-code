
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
#define pi pair<int,int>
#define mp make_pair
#define ss second
#define ff first
#define pb push_back

vector<pi>vec;

void calc_cost(vector<int>a,double &mn_cost,vector<int>&ans)
{
    double cost=0;
    for(int i=0;i<a.size()-1;i++){
        int x1=vec[a[i]].ff,x2=vec[a[i+1]].ff;
        int y1=vec[a[i]].ss,y2=vec[a[i+1]].ss;
        cost+=pow(pow(x1-x2,2)+pow(y1-y2,2),0.5);
        if(cost<mn_cost){
            mn_cost=cost;
            ans=a;
        }
    }
}

void tsp(vector<int>a, int size, int n,double &mn_cost,vector<int>&ans)
{

    if (size == 1)
    {
        calc_cost(a,mn_cost,ans);
        return;
    }

    for (int i=0; i<size; i++)
    {
        tsp(a,size-1,n,mn_cost,ans);
        if (size%2==1)swap(a[0], a[size-1]);

        else swap(a[i], a[size-1]);
    }
}



int main()
{

    freopen("C:/Users/imran/Desktop/input.txt","rb",stdin);
    freopen("output.txt","w",stdout);

    int ct,n,x,y,t;
    cin>>ct;
    t=0;
    while(ct--)
    {
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            vec.pb(mp(x,y));
        }

        vector<int>a,ans;
        for(int i=0;i<n;i++)a.pb(i);

        double mn_cost=1000000000;

        tsp(a,n,n,mn_cost,ans);

        cout<<"Test Case "<<++t<<" : "<<mn_cost<<endl;

    }



    fclose(stdin);
    fclose(stdout);

}
