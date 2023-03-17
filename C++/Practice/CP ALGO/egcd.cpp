#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int gcd(int a, int b, int& x, int& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1 , y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return d;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int x,y;
    cin >> x >> y;
    int a,b;
    int g = gcd(x, y, a, b);
    cout << a << " " << b << en;
    return 0;
}