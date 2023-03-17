#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    int a[n],ans=0;
    for (int i=0; i<n; i++)cin >> a[i];
    sort (a,a+n);
    int i=0;
    for (int i=0; i<n; i++){
        if (k==0) break;
        if (a[i]<0){
            a[i]*=-1;
            k--;
        }
    }
    int mn=INT_MAX;
    for (int i=0; i<n; i++){
        if (a[i] >= 0 && mn>a[i])mn=a[i];
        ans+= a[i];
    }
    if (k%2){
        ans-=2*mn;
    }
    cout << ans << en;
    return 0;
}