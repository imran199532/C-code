#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
#define pi pair<double,double>
#define mp make_pair
#define ss second
#define ff first
#define pb push_back
int pr[mx],sum=0;

vector<pi>vec;
vector<int>graph[mx];

int vis[mx];

double cost_cal(int i,int j)
{
    double x1=vec[i].ff,x2=vec[j].ff;
    double y1=vec[i].ss,y2=vec[j].ss;

    double cs=pow(x1-x2,2)+pow(y1-y2,2);
    double cost=(double)pow(cs,0.5);
    return cost;
}

int find(int r)
{
   return (pr[r]==r)?r:find(pr[r]);
}

void mst(int n)
{

    vector<pair<int,pair<int,int> > >e;
	for(int i=0;i<=n;i++)pr[i]=i;
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)if(i!=j){
            e.push_back(mp(cost_cal(i,j),mp(i,j)));
        }
	}

    sort(e.begin(),e.end());
	int count=0,x,y;
	sum=0;
	for(int i=0;i<e.size();i++)
	{
		x=find(e[i].ss.ff);
		y=find(e[i].ss.ss);
		if(x!=y )
		{
			pr[x]=y;
			count++;
			sum+=e[i].ff;
			graph[e[i].ss.ff].push_back(e[i].ss.ss);

			if(count==n-1) break;
		}
	}

}

void preOrder(vector<int>&ans,int u)
{
    ans.push_back(u);
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        ans.push_back(u);
        preOrder(ans,v);
    }
}

int main()
{

    freopen("C:/Users/imran/Desktop/input1.txt","rb",stdin);
    freopen("output3.txt","w",stdout);

    int ct,n,t;
    double x,y;
    cin>>ct;
    t=0;
    while(ct--)
    {
        vec.clear();
        cin>>n;
        for(int i=0;i<n;i++)graph[i].clear();
        for(int i=0;i<n;i++){
            cin>>x>>y;
            vec.pb(mp(x,y));
        }

        vector<int>ans;
        mst(n);
        preOrder(ans,0);
        cout<<"Test Case "<<++t<<" : "<<sum<<endl;

        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" -> ";



    }



    fclose(stdin);
    fclose(stdout);

}


