#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    ll a=486710859466, b=665228107582;
    cout <<-a/(__gcd(a,b))<<" "<<-b/(__gcd(a,b))<<en;   
    return 0;
}