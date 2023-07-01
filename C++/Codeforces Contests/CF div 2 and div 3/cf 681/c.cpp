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
        ll n;
        cin >>n;
        ll ara1[n],ara2[n];
        vector<pair<ll, ll>>vp;
        for (ll i=0; i<n; i++)cin >>ara1[i];
        ll hi=*max_element(ara1,ara1+n);
        ll sum2=0;
        for (ll i=0; i<n; i++){
            cin >> ara2[i];
            sum2+=ara2[i];
        }
        for (ll i=0; i<n; i++){
            vp.push_back(make_pair(ara1[i],ara2[i]));
        }
        sort (vp.rbegin(),vp.rend());
        ll cnt=0,best=vp[0].first,ans=min(hi,sum2);
        for (ll i=1; i<n; i++){
            cnt+=vp[i-1].second;
            ans=min(ans,max(cnt,vp[i].first));
            if (vp[i].first<cnt){
                ans=min(ans,vp[i-1].first);
                break;
            }
        }
        cout <<ans<<en;
    }   
    return 0;
}