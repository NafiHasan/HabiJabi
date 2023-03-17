#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        int n,p, k,x,y;
        string s;
        cin >>n>>p>>k>>s>>x>>y;
        --p;
        ll cnt[2*n], ans=LLONG_MAX;
        for(int i=0; i<2*n; i++)cnt[i]=0;
        for(int i=n-1; i>=0; i--){
            cnt[i]=cnt[i+k];
            if (s[i]=='0') cnt[i]+=x;
        }
        for(int i=p; i<n; i++) {
            ans= min(ans, (ll)((i-p)*y+cnt[i]));
        }
        cout <<ans<<en;
    }   
    return 0;
}