#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    w(t){
        int x,y;
        cin >> x >> y;
        int ans = x|y;
        cout << ans << "\n";
    }   
    return 0;
}