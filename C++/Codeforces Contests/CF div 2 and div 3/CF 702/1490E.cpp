#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        vector<pair<ll,int>>v(n);
        for (int i=0; i<n; i++){
            ll x;
            cin >>x;
            v[i]={x,i};
        }
        sort (v.begin(), v.end());
        //for (int i=0; i<v.size(); i++)cout <<v[i].first<<" ";
        int start=0;
        for (int i=0; i<n-1; i++){
            if (v[i].first < v[i+1].first)start=i+1;
            v[i+1].first+=v[i].first;
        }
        //cout <<start<<en;
        int ans[n];
        int j=0;
        for (int i=start; i<n; j++,i++){
            ans[j]=v[i].second;
        }
        sort (ans,ans+j);
        cout <<j<<en;
        for (int i=0; i<j; i++)cout <<ans[i]+1 << " ";
        cout <<en;
    }
    return 0;
}