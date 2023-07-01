#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, m, r, c;
 		cin >> n >> m >> r>> c;
 		vector<string>v(n);
 		for (int i=0; i<n; i++)cin >> v[i];
 		bool ans = 0;
 		for (int i=0; i<n; i++){
 			for (int j=0; j<m; j++){
 				if(v[i][j] == 'B')ans = 1;
 			}
 		}
 		if(!ans){
 			cout << "-1\n";
 			continue;
 		}
 		bool found = 0;
 		for (int i=0; i<m; i++){
 			if(v[r-1][i] == 'B')found = 1;
 		}
 		for (int i=0; i<n; i++){
 			if(v[i][c-1] == 'B')found = 1;
 		}
 		if(v[r-1][c-1] == 'B'){
 			cout << "0\n";
 			continue;
 		}
 		if(found)cout << "1\n";
 		else cout << "2\n";
 	}	
    return 0;
}