#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        string s;
        cin >>s;
        for (int i=0; i<s.size(); i++){
            if (i%2==0 && s[i]=='a')s[i]='b';
            else if (i%2==0)s[i]='a';
            else if (i%2==1 && s[i]=='z')s[i]='y';
            else s[i]='z';
        }
        cout <<s<<en;
    }   
    return 0;
}