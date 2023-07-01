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
        int ans=0;
        for (int i=0; i<n-1; i++){
            int x;
            int mn=min(a[i],a[i+1]);
            int mx=max(a[i],a[i+1]);
            x=mx/mn;
            if (mx%mn)x++;
            while(x >2){
                mn*=2;
                ans++;
                x = mx / mn;
                if (mx % mn)
                    x++;
            }
        }
        cout <<ans<<en;
    }
    return 0;
}