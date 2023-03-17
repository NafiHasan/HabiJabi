#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,k;
    cin >> n >>k;
    int a[n];
    bool ans=true;
    for (int i=0; i<n; ++i)cin >> a[i];
    if (k<n){
        for (int i=k-1; i<n; i++){
            if (a[i]!=a[k-1]){
                ans=false;
                break;
            }
        }
    }
    int an=k;
    for (int i=k-1; i>=0; i--){
        if (a[i]==a[k-1])an=i;
        else break;
    }
    if (!ans)cout <<  "-1\n";
    else cout << an << en;
    return 0;
}