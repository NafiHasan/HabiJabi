#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
    int h,w;
    cin >>h>>w;
    if (h<w){
        swap(h,w);
    }
    double a=h/3.0;
    double ans=min(a,(double)w);
    double b=h/2.0, c=w/2.0;
    double opt2=min(b,c);
    ans=max(ans,opt2);
    cout <<ans<<en;   
    return 0;
}