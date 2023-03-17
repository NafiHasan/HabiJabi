#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    freopen("concatenation.in", "r", stdin);
    freopen("concatenation.out", "w", stdout);
    string a,b;
    cin >>a>>b;
    map<char,int>m;
    for (int i=0; i<b.size()-1; i++)m[b[i]]++;
    ll cnt=0;
    for (int i=1; i<a.size(); i++){
        if (m[a[i]]>0)cnt+=m[a[i]];
    }
    ll s1=(ll)a.size(), s2=(ll)b.size();
    ll ans=s1*s2-cnt;
    cout <<ans<<en;
    return 0;
}