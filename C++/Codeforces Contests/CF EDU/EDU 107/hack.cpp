#include<bits/stdc++.h>
using namespace std;
typedef        long long int   ll;
typedef      long double   ld;
typedef     vector<ll>      vll;
#define     fi              first
#define     print(v)        for(ll i:v) cout<<i<<ss
#define     se              second
#define     pb              push_back
#define     nn              "\n"
#define     all(p)          p.begin(),p.end()
#define     zz(v)           (ll)v.size()
#define     S(a)            scanf("%lld",&a)
#define     SS(a,b)         scanf("%lld %lld",&a,&b)
#define     SSS(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define     ss              ' '
#define     pii             pair<ll,ll>
#define     gcd(a,b)        __gcd(a,b)
#define     lcm(a,b)        (a*b)/gcd(a,b)
const double eps = 1e-7;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,q;
    cin>>n>>q;
    ll a[n+1];
    map<ll,ll>mp;
    vll v;
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
        if(mp[a[i]])
            continue;

        v.pb(a[i]);

        mp[a[i]]=i;
    }

    while(q--)
    {
        ll q1;
        cin>>q1;
        cout<<mp[q1]<<ss;
        ll x=mp[q1];
        for(ll i=0; i<zz(v); i++)
        {
            ll y=mp[v[i]];
            if(y<x)
            {
                mp[v[i]]++;
            }

        }
        mp[q1]=1;
    }
    cout<<nn;

}


/* Final check before submit :

1. array size or integer overflow,like uninitialised 0 index.

2. Think twice,code once.check all possible counter test case.

3. Be careful about corner case! n=1?k=1? something about 0?

4. avoid stupid mistake!complexity(t/m)?precision error?submit same code twice?

5. if got WA than remember that you are missing something common.
   *** Be confident!!! who knows? may be your one step back to AC ***
4. minus mod ans=(ans-k+mod)%mod;

*/


/* IF WA???

1. corner case! n=1?k=1? something about 0?

2. check code(avoid stupid mistake)

3. read the statement again(if there any missing point???)

4. check the idea(check all possible counter test case again!!!)

5. be calm,don't be panic!!!.(***this problem not going to decide your future***)

6. don't waste too much time. move to next problem

*/
