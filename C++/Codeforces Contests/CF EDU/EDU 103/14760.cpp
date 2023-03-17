#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int n,k;
        cin >>n>>k;
        if (n==k)cout <<"1\n";
        else if (n<k){
            int ans=k/n;
            if (k%n)ans++;
            cout <<ans<<en;
        }
        else {
            if (n%k==0)cout <<"1\n";
            else cout <<"2\n";
        }
    }
    return 0;
}