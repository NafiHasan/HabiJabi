#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	w(t){
 		string s;
 		cin >> s;
 		string sr=s;
 		int n=s.size();
 		sort(sr.begin(),sr.end());
 		if (s==sr)cout << "YES\n";
 		else {
 			int done=0;
 			bool ans=1;
 			for (int i=1; i<s.size(); i++){
 				if (s[i]==s[i-1] && s[i]=='0' && done==1){
 					ans=0;
 					break;
 				}
 				else if (s[i]==s[i-1] && s[i]=='1')done=1;
 			}
 			if (ans)cout << "YES\n";
 			else cout << "NO\n";
 		}
 	}	
    return 0;
}