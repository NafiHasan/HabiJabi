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
        int n,m;
        string s;
        cin>>n>>m>>s;
        int mx=0,cnt=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='1'){
                mx=max(cnt,mx);
                cnt=0;
            }
            else {
                cnt++;
                mx=max(cnt,mx);
            }
        }
        if (mx>m)cout <<"yes\n";
        else cout <<"no\n";
    }   
    return 0;
}