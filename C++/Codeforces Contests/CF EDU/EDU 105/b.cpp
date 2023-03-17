#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n,u,r,d,l;
        cin >>n>>u>>r>>d>>l;
        int u2=u, r2=r, l2=l, d2=d;
        bool ans=1;
        if (u==n){
            r2--;
            l2--;
        }
        else if (u==n-1){
            if (r2>l2){
                r2--;
            }
            else l2--;
        }
        if (r2<0)ans=0;
        if (r == n)
        {
            u2--;
            d2--;
        }
        else if (r == n - 1)
        {
            if (u2 > d2)
                u2--;
            else
                d2--;
        }
        if (d2<0)ans=0;
        if (d == n)
        {
            r2--;
            l2--;
        }
        else if (d == n - 1)
        {
            if (r2 > l2)
            {
                r2--;
            }
            else
                l2--;
        }
        if (l2<0)ans=0;
        if (l == n)
        {
            u2--;
            d2--;
        }
        else if (l == n - 1)
        {
            if (u2 > d2)
                u2--;
            else
                d2--;
        }
        //cout << u2<<" "<< r2<<" "<<d2<<" "<<l2<<en;
        if (u2<0 || d2<0 || r2<0 || l2<0 || ans==0)cout <<"NO\n";
        else cout <<"YES\n";
    }   
    return 0;
}