#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

const ll p=1e9+7;

void binarySearch(ll n, ll x_position, ll &cnt_big, ll &cnt_less)
{
    ll left = 0, right = n;

    while (left < right)
    {
        ll middle = (left + right) / 2;
        if (x_position >= middle)
        {
            if (x_position != middle)
                cnt_less++;
            left = middle + 1;
        }
        else if (x_position < middle)
        {
            cnt_big++;
            right = middle;
        }
    }//cout <<cnt_big<<en<<cnt_less<<en;
}
ll fact(ll n){
    ll sum=1;
    for (ll i=2; i<=n; i++ ){
        sum=sum*i;
        sum%=p;
    }
    return sum;
}
ll npr(ll n, ll r){
    ll sum=1;
    for (ll i=n; i>(n-r); i--){
        sum*=i;
        sum%=p;
    }
    return sum;
}
int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n, val,pos;
    cin >>n>>val>>pos;
    ll other;
    ll cnt_big=0,cnt_less=0;
    binarySearch(n,pos, cnt_big, cnt_less);
    other =n-cnt_big-cnt_less-1;
    ll ans=(fact(other)*npr((n-val),cnt_big)%p)*npr(val-1,cnt_less);
    ans%=p;
    cout <<ans<<en;
    return 0;
}