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
        int ara[n];
        for (int i=0; i<n; i++)cin >>ara[i];
        for (int i=0, j=n-1; i<=j ; i++,j--){
            if (i!=j) cout <<ara[i]<<" "<<ara[j]<<" ";
            else cout <<ara[i]<<" ";
        }
        // if (n==1)cout <<ara[0];
        cout << en;
    }   
    return 0;
}