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
        int n;
        cin >>n;string s;
        cin >>s;
        bool ans=false;
        if (s[0]=='2' && s[1]=='0' && s[2]=='2' && s[3]=='0') ans= true;
        else if ( s[0]=='2' && s[n-3]=='0' && s[n-2] =='2' && s[n-1]=='0')ans=true;
        else if (s[n-4]=='2' && s[n-3]=='0' && s[n-2]=='2' && s[n-1]=='0')ans=true;
        else if (s[0]=='2' && s[1]=='0' && s[n-2]=='2' && s[n-1]=='0')ans=true;
        else if (s[0]=='2' && s[1]=='0' && s[2]=='2' && s[n-1]=='0')ans=true;
        if (ans)cout <<"YES\n";
        else cout <<"NO\n";
    }   
    return 0;
}