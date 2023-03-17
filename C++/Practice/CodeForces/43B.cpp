#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    string s1,s2;
    map<char,int>use;
    getline(cin,s1);
    bool ans =1;
    getline(cin,s2);
    //cout << s1.size() << "  " << s2.size() << en;
    for (int i=0; i<s1.size(); i++) if (s1[i]!=' ')use[s1[i]]++;
    for (int i=0; i<s2.size(); i++){
        if (s2[i]==' ')continue;
        if (use[s2[i]])use[s2[i]]--;
        else {
            ans=0;
            break;
        }
    }
    if (ans)cout << "YES\n";
    else cout << "NO\n";
    return 0;
}