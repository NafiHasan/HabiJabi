#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n, x;
    cin >> n >>x;
    int a[n];
    for (int i= 0; i<n; i++)cin >> a[i];
    for(int i=0 ; i<n; i++)if(a[i]!=x)cout << a[i]<<" ";
    cout << en;
    return 0;
}