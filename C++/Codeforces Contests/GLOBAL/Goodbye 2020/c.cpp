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
        string s;
        cin >>s;
        int ans=0;
        for(int i=1; i<s.size(); i++){
            if(s[i]==s[i-1] || s[i]==s[i-2]){
                s[i]='/';
                ans++;
            }
        }
        cout << ans << en;
    }   
    return 0;
}