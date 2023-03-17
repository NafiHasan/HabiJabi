#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++)cin >> a[i];
    if (n==1){
        cout << 1 << en;
        return 0;
    }
    vector<pair<int,int>>v;
    int start=0, end;
    for (int i=2; i<n; i++){
        if (a[i]!=a[i-1]+a[i-2]){
            v.push_back({start, i - 1});
            start=i-1;
        }
        if (i==n-1 && a[i]== a[i-1]+a[i-2]){
            v.push_back({start,i});
        }
    }
    int mx=0;
    for (int i =0; i<v.size(); i++){
        mx=max(mx, v[i].second-v[i].first+1);
    }
    cout << max(mx,2) << en;
    return 0;
}