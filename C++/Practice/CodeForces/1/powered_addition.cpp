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
        int n;
        cin >>n;
        ll ara[n];
        ll best=0;
        for (int i=0; i<n; i++)cin >>ara[i];
        ll hi=ara[0];
        for (int i=0; i<n; i++){
            if (i && ara[i]<hi){
                best = max(best, abs(hi- ara[i]));
            }
            hi = max(hi, ara[i]);
        }
        ll ans;
        if (best==0)ans=0;
        else ans=log2(best);
        if (pow(2,(ans-1))<best)ans++;
        cout <<ans<<en;
    }   
    return 0;
}