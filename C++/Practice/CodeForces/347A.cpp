#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++)cin >>  a[i];
    sort (a,a+n);
    cout << a[n-1]<< " ";
    for (int i=1; i<n-1; i++)cout << a[i] << " ";
    cout << a[0] << en;
    return 0;
}