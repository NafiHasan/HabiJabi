#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        int x,y;
        cin >>x>>y;
        string s;
        cin >>s;
        int l=0,u=0,d=0,r=0;
        bool ans=true;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='U')u++;
            else if (s[i]=='D')d++;
            else if (s[i]=='L')l++;
            else if (s[i]=='R')r++;
        }
        if (x>0 && r<x)ans=false;
        if (x < 0 && l < abs(x))
            ans = false;
        if (y > 0 && u < y)
            ans = false;
        if (y < 0 && d < abs(y))
            ans = false;
        if (ans)cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}