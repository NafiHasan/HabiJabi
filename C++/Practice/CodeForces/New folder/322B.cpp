#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int r,g,b;
    cin >>r >> g>> b;
    int rr=r,gg=g,bb=b;
    int best = 0, ans = 0, ans2=0;
    if (1){
        ans += r / 3;
        r %= 3;
        ans += g / 3;
        g %= 3;
        ans += b / 3;
        b %= 3;
        ans += min({r, g, b});
    }
    if (1){
        ans2+=min({rr,gg,bb});
        rr-=ans2, bb-=ans2, gg-=ans2;
        ans2+=rr/3+gg/3+bb/3;
    }
    best=max(ans,ans2);
    cout <<best<<en;
    return 0;
}