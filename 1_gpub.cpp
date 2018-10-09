#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
#define pi pair<int,int>
#define mp make_pair
#define ss second
#define ff first
#define pb push_back


int main()
{

    freopen("A-large.in","rb",stdin);
    freopen("output.txt","w",stdout);

    int t,x,y;
    cin>>t;
    int cnt[5005];
    int ct=0;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x>>y;
            for(int j=x;j<=y;j++)cnt[j]++;
        }
        int q;
        cin>>q;
        cout<<"Case #"<<++ct<<": ";
        for(int j=0;j<q;j++){
            cin>>x;
            if(j!=q-1)cout<<cnt[x]<<" ";
            else cout<<cnt[x];
        }
        cout<<endl;


    }

    fclose(stdin);
    fclose(stdout);

}

