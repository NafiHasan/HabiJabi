#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int  n;
    cin >> n;
    if(n<11){
        cout << "0\n";
        return 0;
    }
    n-=10;
    if(n==1 || n==11) cout << "4\n";
    else if (n==10)cout << "15\n";
    else if (n>1 && n<10) cout << "4\n";
    else cout << "0\n";
    return 0;
}