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
		int cnt = 0;
		for (int i=0; i<n; i++)if(s[i] == 'N')cnt++;
		if(cnt > 1 || cnt == 0)cout << "YES\n";
		else cout << "NO\n";
	}		
    return 0;
 }