#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define dbg(x) cout<<#x<<" = "<<x<<en
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 

int main()
{
    fast_io();
    w(t){
        int n,k;
        cin >> n >>k;
        int ans=k/2;
        ans+=n-k;
        cout <<ans <<en;
        if (ans){
            for (int i = (k + 1) / 2; i < k; i++)
                cout << i << " ";
            for (int i = k + 1; i <= n; i++)
                cout << i << " ";
            cout << en;     
        }
    }
    return 0;
}