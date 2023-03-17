#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        ll n;
        cin >>n;
        double ans=(-1.0+(sqrt(1.0+8.0*(double)n)))/2.0;
        ans=ceil(ans);
        ll mul=(ll)ans*((ll)ans+1)/2;
        // cout <<mul<<en;
        // cout <<ans<<en;
        if (mul-n>1 || mul==n)cout <<(ll)ans<<en;
        else cout <<(ll)ans+1<<en;
    }
    return 0;
}