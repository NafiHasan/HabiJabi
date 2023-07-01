#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
const long long p=1e9+7;

ll fac[100005];
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x %= p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll modinv(ll n, int p)
{
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
    int tc;
    cin >> tc;
    while(tc--){
        int n, k;
        cin >> n >> k;
        vector<int>v(n);
        map<int,int>m;
        for(int i=0 ;i<n; i++){
            cin >> v[i];
            m[v[i]]++;
        }
        sort(v.rbegin(), v.rend());
        ll crnt=1, num=v[0];
        k--;
        for(int i=1; i<n && k; i++){
            if(v[i]==v[i-1])crnt++;
            else {
                crnt = 1;
                num=v[i];
            }
            k--;
        }
        //cout <<crnt<<" "<<m[num]<< en;
        cout << ncr(m[num],crnt) << "\n";
    }   
    return 0;
}