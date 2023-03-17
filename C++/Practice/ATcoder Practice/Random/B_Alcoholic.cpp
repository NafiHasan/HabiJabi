#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,lim;
    cin >> n >> lim;
    int ans=-1; 
    double cnt=0;
    for(int i=0; i<n; i++){
        double x,y;
        cin >> x >>y;
        cnt+=(double)x*y/100.0;
        //cout <<cnt-(double)lim<<en;
        if((double)(cnt - (double)lim) > 1e-3  && ans==-1){
            ans = i + 1;
        }
    }
    cout <<ans<<en;   
    return 0;
}