#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int rec(int n){
    if(n<=0)return n+1;
    int x= rec(n-2);
    cout << x << en;
    return x;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n;
    int x= rec(n);
    cout << "x = " << x << en;
    return 0;
}