#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >>n;
    int a[n],cnt[1010];
    memset(cnt,0,sizeof(cnt));
    for (int i=0; i<n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int mx=*max_element(cnt,cnt+1010);
    if (mx<=((n+1)/2))cout << "YES\n";
    else cout << "NO\n";
    return 0;
}