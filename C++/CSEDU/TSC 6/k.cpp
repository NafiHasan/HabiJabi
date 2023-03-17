#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
const ll p=1e9+7;
ll fac[100005];
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x %= p;
    while (y > 0){
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll modinv(ll n,int p){
    return power(n, p - 2, p);
}
ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fac[n] * modinv(fac[r], p) % p * modinv(fac[n - r], p) % p) % p;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    fac[0] = 1;
    for (int i = 1; i <= 100002; i++)
        fac[i] = (fac[i - 1] * i) % p;
    w(t){
        int a,b,c,k,must;
        cin >>a>>b>>c>>k>>must;
        ll ans=0;
        ans+=ncr((ll)c,(ll)must);
        k-=must;
        if (k<2)ans=0;
        if (a>b)swap(a,b);
        int ind1, ind2=k-1;
        ind2=min(ind2,b);
        ind1=k-ind2;
        ll cnt=0;
        ll minus=0;
        for (int i=ind1; i<=(ind1+ind2)/2; i++){
            cnt+=((ncr((ll)a,(ll)i)%p) * (ncr((ll)b,(ll)k-i)%p))%p;
            //cout <<cnt<<" ";
            if (i==(k-i))
                minus = ((ncr((ll)a, (ll)i) % p) * (ncr((ll)b, (ll)k - i) % p)) % p;
            cnt%=p;
            //cout <<cnt<<en;
        }
        cnt*=2;
        cnt%=p;
        cnt-=minus;
        ans=((ans%p)*(cnt%p))%p;
        if (ans>0) cout <<ans<<en;
        else cout <<"0\n";
    }   
    return 0;
}