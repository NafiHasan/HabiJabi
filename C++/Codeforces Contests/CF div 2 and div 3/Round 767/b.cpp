#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define dbg(x) cout<<#x<<" = "<<x<<en
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 

int main()
{
    fast_io();
    int tc;
    cin >> tc;
    while(tc--){
        int a , b, k;
        cin >> a >> b >> k;
        if(a == b && a > 1){
            cout << "YES\n";
            continue;
        }
        int all = 0;
        all = (b - a)/ 2;
        if(a % 2 || b % 2)all++;
        if(k >= all)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}