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
        cin >> n;
        ll x[n],y[n];
        for (int i=0; i<n; i++)cin >> x[i] >> y[i];
        sort(x,x+n);
        sort(y,y+n);
        int mid1=n/2,mid2=mid1;
        if(n%2==0)mid2--;
        ll a=abs(x[mid1]-x[mid2])+1;
        ll b=abs(y[mid1]-y[mid2])+1;
        cout << a*b << en;
    }
    return 0;
}