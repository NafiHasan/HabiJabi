#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >>n;
    vector<ll>a(n),b(n);
    for(int i=0; i<n; i++)cin >>a[i];   
    for(int i=0; i<n; i++)cin >>b[i];
    ll sum=0;
    for(int i=0; i<n; i++)sum+=a[i]*b[i];
    if(sum==0) cout << "Yes" << en;   
    else cout << "No\n";
    return 0;
}