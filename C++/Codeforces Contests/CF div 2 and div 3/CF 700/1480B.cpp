#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        ll a,b,n;
        cin >>a>>b>>n;
        ll atk[n],hel[n];
        for(ll i=0; i<n; i++)cin >>atk[i];
        for(ll i=0; i<n; i++)cin >>hel[i];
        vector<pair<ll,ll>>dam(n);
        for (ll i=0; i<n; i++){
            ll cnt=hel[i]/a;
            if (hel[i]%a!=0)cnt++;
            cnt*=atk[i];
            dam[i]={atk[i],i};
        }
        sort (dam.begin(),dam.end());
        ll ans=0;
        for (ll i=0; i<n; i++){
            if (b<=0)break;
            ll cnt = hel[dam[i].second] / a;
            if (hel[dam[i].second] % a != 0)
                cnt++;
            cnt *= dam[i].first;
            if (b<cnt){
                ll hi=b/atk[dam[i].second];
                if (b %atk[dam[i].second]!=0)hi++;
                //cout <<hi<<en;
                if (hel[dam[i].second] > a*hi)break;
            }
            b-=cnt;
            ans++;
        }
        if (ans==n)cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}