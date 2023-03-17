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
    ll a[n];
    for (int i=0; i<n; i++)cin >>a[i];
    ll best=0;
    int i=0, j=n-1;
    while(i<j){
        bool done=true;
        best=max(best,(j-i)*(a[i]+a[j]));
        if (i+1<j && (a[i+1]+a[j])*(j-i-1)>best){
            i++;
            best = max(best, (j - i) * (a[i] + a[j]));
            done = false;
        }
        if (j-1 >i && (a[j-1]+a[i])*(j-i-1) > best){
            j--;
            best = max(best, (j - i) * (a[i] + a[j]));
            done =false;
        }
        if (done)break;
    }
    cout <<best<<en;
    return 0;
}