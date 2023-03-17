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
    
    ll n,cnt=1;
    cin >>n;
    if (n==0){
        cout << "1\n";
        return 0;
    }
    ll dig=(ll)log2((ll)n);
    //cout <<dig+1<<en;
    dig++;
    for (ll i=0; i< dig; i++){
        if ((((ll)1<<i) & n) == 0)cnt*=2;
    } 
    cout <<cnt<<en;
    return 0;
}