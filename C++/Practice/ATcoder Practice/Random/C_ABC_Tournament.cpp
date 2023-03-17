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
    cin >> n;
    int si=pow(2,n);
    vector<int>v(si);
    for(int i=0; i<si; i++)cin >> v[i];
    int ans1=0, ans2=0,mn1=0,mn2=0;
    for(int i=0; i<si/2; i++){
        if(v[i]>mn1){
            mn1=v[i];
            ans1=i+1;
        }
    }
    for (int i = si/2; i < si ; i++){
        if (v[i] > mn2)
        {
            mn2 = v[i];
            ans2 = i + 1;
        }
    }
    if(mn1<mn2) cout << ans1<<en;
    else cout << ans2 << en;
    return 0;
}