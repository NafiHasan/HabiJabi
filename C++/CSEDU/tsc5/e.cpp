#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >>n;
    int mn=1;
    vector<pair<string,int>>v(n);
    vector<pair<double,double>>ans(n);
    for (int i=0; i<n; i++){
        string s;
        int x;
        cin >>s>>x;
        v[i]={s,x};
        mn=min(mn,x);
    }
    double sum=0;
    for (int i=0; i<n; i++){
        if (mn!=0)ans[i]={(double)v[i].second-.5,(double)v[i].second+.49};
        else ans[i] = {(double)v[i].second,(double)v[i].second + .49 };
        sum+=ans[i].second;
    }
    if (sum<100.00) cout << "IMPOSSIBLE\n";
    else {
        for (int i=0; i<n; i++){
            cout <<v[i].first<<" "<<fixed<<setprecision(2) <<ans[i].first<<" "<<fixed<<setprecision(2)<<ans[i].second<<en;
        }
    }
    return 0;
}