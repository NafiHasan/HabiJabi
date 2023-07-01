#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	int tc;
	cin >> tc;
	while(tc--){
		string s, t, ans = "";
		cin >> s >> t;
		int n = s.size();
		sort (s.begin(), s.end());
		int fb = 0, fc = 0, fa = 0;
		for (int i=0; i<n; i++){
			if(s[i] == 'b')fb++;
			if(s[i] == 'c')fc++;
			if(s[i] == 'a')fa++;
		}
		if(t == "abc" && fb > 0 && fc > 0 && fa > 0){
			for (int i=1; i<=fa; i++)ans+="a";
			for (int i=1; i<=fc; i++)ans+="c";
			for (int i=1; i<=fb; i++)ans+="b";
			for (int i=0; i<n; i++)if(s[i] != 'a' && s[i] != 'b' && s[i] != 'c')ans+=s[i];
		}
		else ans = s;
		cout << ans << '\n';
	}
    return 0;
}