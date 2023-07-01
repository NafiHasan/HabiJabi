#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        int a[n];
        for (int i=0; i<n; i++)cin >>a[i];
        int cnt=1, ans=1;
        for (int i=1; i<n; i++){
            if (a[i]==a[i-1]){
                cnt++;
                ans=max(ans,cnt);
            }
            else cnt=1;
        }
        cout <<ans<<en;
    }   
    return 0;
}