#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        int a[n];
        int c0 = 0, c1 = 0, c2 = 0;
        for (int i=0; i<n; i++){
            cin >> a[i];
            if (a[i]%3==1)c1++;
            else if (a[i]%3==0)c0++;
            else c2++;
        }
        int need=n/3;
        int ans=0;
        int got0=0,got1=0,got2=0;
        if (c0>need){
            ans+=c0-need;
            c1+=c0-need;
        }
        else if (c0<need){
            ans += need-c0;
            c2 -=need-c0;
        }
        c0=need;
        if (c1>need){
            ans+=c1-need;
            c2+=c1-need;
        }
        else if (c1 < need)
        {
            ans += need - c1;
            c0 -= need - c1;
        }
        c1=need;
        if (c2 > need)
        {
            ans += c2 - need;
            c0 += c2 - need;
        }
        else if (c2 < need)
        {
            ans += need - c2;
            c1 -= need - c2;
        }
        cout <<ans<<en;
    }
    return 0;
}