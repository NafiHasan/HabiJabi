#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    w(t){
        ll a ,b ,c,d;
        int ara[3];
        for (int i=0; i<3; i++)cin >>ara[i];
        sort (ara,ara+3);
        ll ans = ara[2] + ara[1] - ara[0];
        cout <<ans <<endl;
    }
    return 0;
}