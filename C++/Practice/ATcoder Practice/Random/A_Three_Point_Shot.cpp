#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    if(a>b)swap(a,b);
    if(a+3>b)cout <<"Yes\n";
    else cout << "No\n";   
    return 0;
}