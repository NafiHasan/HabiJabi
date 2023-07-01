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
    
    int n;
    cin >>n;
    ll ans=(ll)n;
    while(n>=2){
        if (ans%(ll)n!=0){
            ans=(ll)(ans*n)/(__gcd(ans,(ll)n));
        }
        n--;
    }   
    cout <<ans+1<<en;
    return 0;
}