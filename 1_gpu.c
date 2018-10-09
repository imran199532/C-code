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

    freopen("C:/Users/imran/Desktop/input.txt","rb",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    int cnt[505];
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
            if(j!=q-1)cout<<cnt[j]<<" ";
            else cout<<cnt[j];
        }


    }

    fclose(stdin);
    fclose(stdout);

}
