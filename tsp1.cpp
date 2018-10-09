
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


void calc_cost(vector<int>a,double &mn_cost,vector<int>&ans)
{

    double cost=0.0;
    int n=a.size();
    for(int i=0;i<a.size();i++){
        double x1=vec[a[i]].ff,x2=vec[a[(i+1)%n]].ff;
        double y1=vec[a[i]].ss,y2=vec[a[(i+1)%n]].ss;

        double cs=pow(x1-x2,2)+pow(y1-y2,2);
        cost+=(double)pow(cs,0.5);

        if(i==a.size()-1)continue;
        for(int k=0;k<i;k++){
            double x3=vec[a[k]].ff,y3=vec[a[k]].ss;
            if((y3-y1)*1.0/(x3-x1)==(y1-y2)*1.0/(x1-x2))return;
        }

    }

    if(cost<mn_cost){
        mn_cost=cost;
        ans=a;
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

   // freopen("C:/Users/imran/Desktop/input1.txt","rb",stdin);
    freopen("C:/Users/imran/Desktop/OFFLINE_1_1305032/1305032_test_cases.txt","rb",stdin);


    //freopen("output1.txt","w",stdout);

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

        vector<int>a,ans;
        for(int i=0;i<n;i++)a.pb(i);

        double mn_cost=1000000000;

        tsp(a,n,n,mn_cost,ans);


        cout<<"Test Case "<<++t<<" : "<<mn_cost<<endl;

        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" -> ";

        cout<<ans[0]<<endl<<endl;

    }



    fclose(stdin);
    //fclose(stdout);

}
