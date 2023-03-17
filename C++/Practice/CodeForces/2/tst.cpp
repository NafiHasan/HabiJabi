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
        ll len;
        cin >> len; 
        cout << en ;
        if (len < n) {
            len ++ ;
        }
        else {
            len--;
        }
    }   
    return 0;
}