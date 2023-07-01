#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int n,m;
 	cin >> n >> m;
 	string s;
 	cin >> s;
 	int cnt = 0;
 	for (int i=0; i<n; i++){
 		if(s[i] == 'a' && i < n-2 && s[i+1] == 'b' && s[i+2] == 'c')cnt++;
 	}
 	for (int i=0; i<m; i++){
 		int pos;
 		char c;
 		cin >> pos >> c;
 		pos--;
 		if(s[pos] == 'a' && pos < n-2 && s[pos + 1] == 'b' && s[pos + 2] == 'c')cnt--;
 		else if(s[pos] == 'b' && pos < n-1 && pos > 0 && s[pos + 1] == 'c' && s[pos-1] == 'a')cnt--;
 		else if(s[pos] == 'c' && pos > 1 && s[pos - 1] == 'b' && s[pos - 2] == 'a')cnt--;
 		s[pos] = c;
 		if(s[pos] == 'a' && pos < n-2 && s[pos + 1] == 'b' && s[pos + 2] == 'c')cnt++;
 		else if(s[pos] == 'b' && pos < n-1 && pos > 0 && s[pos + 1] == 'c' && s[pos-1] == 'a')cnt++;
 		else if(s[pos] == 'c' && pos > 1 && s[pos - 1] == 'b' && s[pos - 2] == 'a')cnt++;
 		cout << cnt << '\n';
 	}
 	// cout << cnt << '\n';z
    return 0;
}