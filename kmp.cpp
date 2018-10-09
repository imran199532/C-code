#include <bits/stdc++.h>
using namespace std;
#define mx 100010

int f[mx];

void preKMP(string pattern)
{

    int m = pattern.size(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])break;
            else k = f[k];
        }
        f[i] = k + 1;
    }
}
//check whether target string contains pattern

void KMP(string target, string pattern)
{
    int m = pattern.length();
    int n = target.length();
    preKMP(pattern);
    cout<<target<<endl<<pattern;

    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m){
                cout<<i<<endl;
                k=f[k];
            }
        }
        else k=f[k];
    }
    return;
}



int main()
{

    freopen("input_1_naive.txt","rb",stdin);
    string T;
    cin>>T;
    string P;
    cin>>P;
    cout<<T<<" "<<P<<endl;
    //KMP(T,P);

}
