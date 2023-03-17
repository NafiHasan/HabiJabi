#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int c=1;
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        int a[n];
        for (int i=0; i<n; i++)cin >> a[i];
        int ans=*max_element(a,a+n);
        cout << "Case " << c++ << ": " << ans << en;
    }
    return 0;
}