#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		string s;
 		cin >> s;
 		int n = s.size();
 		if(n%2 == 0){
 			bool ans = 1;
 			for (int i=0, j = n/2; i<n/2; j++,i++){
 				if(s[i] != s[j])ans = 0;
 			}
 			if(ans)cout <<"YES\n";
 			else cout << "NO\n";
 		}
 		else cout << "NO\n";
 	}	
    return 0;
}