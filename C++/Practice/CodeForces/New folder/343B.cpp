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
    cin  >> s;
    stack<char>a;
    for(int i=0; i<s.size(); i++){
        if(a.empty()) a.push(s[i]);
        else if(a.top() == s[i])a.pop();
        else a.push(s[i]);
    }   
    if (a.empty())cout <<"YES\n";
    else cout << "NO\n";
    return 0;
}