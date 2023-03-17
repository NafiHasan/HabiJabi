#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    ll n;
    cin >>n;
    for (ll i=0; i<37; i++){
        for (ll j=0; j<25; j++){
            if ((ll)pow(3,i)+pow(5,j)==n){
                cout <<i<<" "<<j<<"\n";
                return 0;
            }
        }
    }
    cout <<"-1\n";
    return 0;
}