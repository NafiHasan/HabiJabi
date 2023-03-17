#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

string s;
void solve(int tc = 0)
{
    cin >> s;
    if (s.length() % 2)
    {
        cout << "NO\n";
        return;
    }

    if (s[0] == ')' || s[s.length() - 1] == '(')
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        solve();
    }
    return 0;
}