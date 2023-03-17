#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n,u,v;
        cin >>n>>u>>v;
        int a[n];
        for (int i=0; i<n; i++)cin >>a[i];
        int mx=0;
        for (int i=0; i<n-1; i++){
            mx=max(mx,abs(a[i]-a[i+1]));
        }
        if (mx==0){
            ll ans=(ll)(u+v);
            //ans=min(ans,(ll)2*u);
            ans=min(ans,(ll)2*v);
            cout <<ans<<en;
        }
        else if(mx==1){
            int ans=min(u,v);
            cout <<ans<<en;
        }
        else cout << "0\n";
    }   
    return 0;
}