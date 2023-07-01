#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        int n;
        cin >>n;
        int ara[n];
        for (int i=0; i<n; i++){
            cin >>ara[i];
        }
        for (int i=n-1; i>=0; i--){
            if (i<n/2)cout <<-1*ara[i]<<" ";
            else cout <<ara[i]<<" ";
        }
        cout <<en;
    }
    return 0;
}