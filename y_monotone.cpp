#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
#define pi pair<double,double>
#define mp make_pair
#define ss second
#define ff first
#define pb push_back

map<pi,pi>prev,next;

pi nodes[mx];


int main()
{

    freopen("C:/Users/imran/Desktop/input.txt","rb",stdin);


    int n;
    double x,y;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x>>y;
        pi cur=mp(x,y);
        nodes[i]=cur;
    }

    for(int i=0;i<n;i++){
        pi p=nodes[i];
        pi q=nodes[(i-1+n)%n];
        pi r=nodes[(i+1)%n];

        prev[p]=q;
        next[p]=r;
    }




    fclose(stdin);


}

