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
        int n; cin >>n;
        string s;
        cin >>s;
        int cnt=0;
        for (int i=n-1; i>=0; i--){
            if (s[i]!=')')break;
            else cnt++;
        }
        int rem=n-cnt;
        if (cnt>rem)cout <<"Yes\n";
        else cout <<"No\n";
    }
    return 0;
}