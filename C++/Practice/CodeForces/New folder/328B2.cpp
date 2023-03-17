#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int r,g,b,ans=0;
    cin >>r>>g>>b;
    if (r>3){
        if (r % 3 == 0)
        {
            ans += (r - 3) / 3;
            r = 3;
        }
        else
        {
            ans += r / 3;
            r %= 3;
        }
    }
    if (g > 3)
    {
        if (g % 3 == 0)
        {
            ans += (g - 3) / 3;
            g = 3;
        }
        else
        {
            ans += g / 3;
            g %= 3;
        }
    }
    if (b > 3){
        if (b%3==0){
            ans+=(b-3)/3;
            b=3;
        }
        else {
            ans +=b / 3;
            b %= 3;
        }
    }
    int ans1=min({r,g,b});
    int ans2=r/3+g/3+b/3;
    int best=max(ans+ans2, ans+ans1);
    cout <<best<<en;
    return 0;
}