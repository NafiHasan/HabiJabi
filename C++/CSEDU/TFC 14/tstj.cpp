#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
    fast_io();
    int n;
    cin >> n;
    cout << 1 << en <<n << en;
    int cnt=0;
    for (int i=1; i<=n; i++){
        cout << i << " ";
        cnt++;
    }
    // cout << en << cnt <<en;    
    return 0;
}