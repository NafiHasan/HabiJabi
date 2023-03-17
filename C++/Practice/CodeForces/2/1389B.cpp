// test
// 1
// 10 7 3 4 6 4 8 8 4 13 1 1 1
// output=54 

#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t) {
        int n,k,z;
        cin >>n>>k>>z;
        int ara[n];
        ll sum[n],mx=0;
        for(int i=0; i<n; i++){
            cin >> ara[i];
            sum[i] = (ll)ara[i];
        }
        for(int i=1; i<=k; i++){
            sum[i]+=sum[i-1];           
        }
        for (int i=1; i<=k; i++){
            int left = min((k - i + 1) / 2,z), right = min(k - i - left + 1,left);
            if (sum[k-left-right] + (right * ara[i]) + (left * ara[i - 1]) > mx ){
                mx = (ll)sum[k-left-right] + right * ara[i] + left * ara[i - 1];
            }
        }
        cout <<mx<<en;
    }  
    return 0;
}