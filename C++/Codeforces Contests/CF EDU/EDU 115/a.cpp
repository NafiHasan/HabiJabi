#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n;
 		cin >>n;
 		string s1, s2;
 		cin >> s1 >> s2;
 		int ans = 1;
 		for (int i=0; i<n; i++){
 			if(s1[i] == s2[i] && s1[i] == '1')ans =0;
 		}
 		if(ans == 0)cout << "NO\n";
 		else cout << "YES\n";
 	}
    return 0;
}