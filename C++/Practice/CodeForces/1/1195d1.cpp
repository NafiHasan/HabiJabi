#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

const ll p = 998244353 ;
int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll n,sz;
    cin >>n;
    vector <string>v;
    vector <ll>vl(10,0);
    for (ll i=0; i<n; i++){
        string s;
        cin >>s;
        sz=s.size();
        v.push_back(s);
        for (ll j=0; j<s.size(); j++){
            vl[j]+=s[j]-'0';
        }
    }
    ll ans=0,cnt,sum;
    for (ll i=sz-1,j=0; i>=0; j++,i--){
        ll po=j*2;
        cnt=pow(10,po);
        cnt%=p;
        sum = ((11 * (n%p) )%p);/////bigmod done with multiple line
        sum%=p;
        sum*= ((vl[i]%p)%p);
        sum %= p;
        sum *= (cnt%p);
        sum%=p;
        ans += sum;
        ans%=p;
    }
    cout << ans % p << en;
    return 0;
}