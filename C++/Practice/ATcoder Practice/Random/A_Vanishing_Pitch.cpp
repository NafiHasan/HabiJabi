#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int v,t,s,d;
    cin >> v >> t >> s >> d;
    int lim1=v*t, lim2=v*s;
    if (d>=lim1 && d<=lim2)cout << "No\n";
    else cout << "Yes\n";
    return 0;
}