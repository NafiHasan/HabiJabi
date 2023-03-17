#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    string s;
    cin >>s;
    if(s[0]==s[1] && s[0]==s[2])cout <<"Won\n";
    else cout << "Lost\n";   
    return 0;
}