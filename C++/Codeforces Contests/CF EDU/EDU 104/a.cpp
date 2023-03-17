#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        int a[n];
        for (int i=0; i<n; i++)cin >>a[i];
        sort (a,a+n);
        int mn=a[0];
        int ans=0;
        for (int i=0; i<n; i++)if (a[i]!=mn)ans++;
        cout <<ans<<en;
    }   
    return 0;
}