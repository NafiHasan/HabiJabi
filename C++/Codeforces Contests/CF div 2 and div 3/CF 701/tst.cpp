#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int x=10, y=20;
    int z= x>y;
    x+= z++ + --y;
    y%= ++x;
    cout << x << ' ' << y << ' ' << z << en;   
    return 0;
}