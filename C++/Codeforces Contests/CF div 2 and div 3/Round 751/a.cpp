#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		string s, s2;
 		cin >> s;
 		s2 = s;
 		sort(s2.begin(), s2.end());
 		int done = 0;
 		int n = s.size();
 		string ans1, ans2 = "";
 		for (int i=0; i<n; i++){
 			if(done == 0 && s[i] == s2[0]){
 				ans1 = s[i];
 				done++;
 			}
 			else ans2+=s[i];
 		}
 		cout << ans1 << ' ' << ans2 << '\n';
 	}	
    return 0;
}