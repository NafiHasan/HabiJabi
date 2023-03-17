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
        int a,b,c;
        cin >>a>>b>>c;
        int mx=max({a,b,c}), mn=min({a,b,c});
        if((a+b+c) == (2*mx+mn)){
            cout << "YES\n";
            cout << mn << " " << mn << " "<< mx<<en;
        }
        else cout <<"NO\n";
    }   
    return 0;
}