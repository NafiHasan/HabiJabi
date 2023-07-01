#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        ll p,a,b,c;
        cin >>p>>a>>b>>c;
        if (p%a==0 || p%b==0 || p%c==0)cout <<"0\n";
        else {
            ll mn = min(a - (p % a), b - (p % b));
            mn = min(mn, c - (p % c));
            cout << mn << en;
        }
    }
    return 0;
}