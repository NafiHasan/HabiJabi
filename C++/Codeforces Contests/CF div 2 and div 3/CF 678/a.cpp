#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    w(t){
        int n,m,sum=0;
        cin >>n>>m;
        int ara[n];
        for (int i=0; i<n; i++){
            cin >>ara[i];
            sum+=ara[i];
        }
        if (sum==m)cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}