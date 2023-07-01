#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	int tc;
	cin >> tc;
	while(tc--){
		string s, s1;
		cin >> s >> s1;
		vector<int>v(100,0);
		for (int i=0; i<26; i++){
			v[s[i] - 'a'] = i+1; 
		}
		int ans = 0;
		for (int i=1; i<s1.size(); i++){
			ans += abs(v[s1[i] - 'a'] - v[s1[i-1]- 'a']);
		}
		cout << ans << '\n';
	}	
    return 0;
}