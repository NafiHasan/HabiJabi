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
    
    ll a,b;
    cin >> a>> b;
    ll hi=2*a+100;
    cout <<hi-b<<en;   
    return 0;
}