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
    int c1=0,c2=0;
    for (int i=0; i<n; i++){
        cin >> a[i];
        if (a[i]==100)c1++;
        else c2++;
    }
    if (n==1 || c1%2==1){
        cout << "NO\n";
        return 0;
    }
    if ((c1 && c1%2==0) || (c2%2==0 && c1%2==0)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}