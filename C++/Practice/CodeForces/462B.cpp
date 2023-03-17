#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    ll n,k;
    cin >>n >>k;
    string s;
    cin >> s;
    map<char,ll>m;
    for (int i=0; i<s.size(); i++)m[s[i]]++;
    ll cnt[30];
    memset(cnt,0,sizeof(cnt));
    for (int i=65; i<91; i++){
        cnt[i-65]=m[i];
    }
    sort (cnt,cnt+30, greater<ll>());
    ll ans=0;
    for (int i=0; i<31; i++){
        if (cnt[i]>=k){
            ans+=k*k;
            k=0;
            break;
        }
        else {
            ans+=cnt[i]*cnt[i];
            k-=cnt[i];
            
        }
    }
    cout << -1 % 1000000007 << en;
    cout << ans<< en;
    return 0;
}