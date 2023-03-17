#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans=0;
    for (int i=0; i<=(n/a)+1; i++){
        for (int j=0; j<=(n/b)+1; j++){
            if ((n-(a*i+b*j))%c ==0){
                int cnt = (n - (a * i + b * j))/c;
                if (cnt>=0) ans = max(ans, i + j +cnt);
                //if (ans>4000) cout << i << " " << j << " " << cnt <<en;
            }
        }
    }
    cout << ans << en;
    return 0;
}