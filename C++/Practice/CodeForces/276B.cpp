#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    string s;
    cin >> s;
    vector <int>a(30,0);
    for (int i=0; i<s.size(); i++)a[s[i]-97]++;
    int odd=0;
    for (int i=0; i<30; i++)if (a[i]%2)odd++;
    if (odd <=1){
        cout << "First\n";
        return 0;
    }
    else {
        if (odd%2==0)cout << "Second\n";
        else cout << "First\n";
    }
    return 0;
}