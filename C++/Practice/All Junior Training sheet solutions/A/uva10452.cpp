#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool valid(int ro, int col, int n){
	if(ro < 0 || col < 0 || col >= n)return 0;
	return 1;
}

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int m, n;
 		cin >> m >> n;
 		vector<string> v(m);
 		for (int i=0; i<m; i++)cin >> v[i];
 		int stj;
 		for (int i=0; i<n; i++)if(v[m-1][i] == '@')stj = i;
 		string ans = "IEHOVA#";
 		int ro = m-1, col = stj;
 		for(int i=0; i<ans.size(); i++){
 			if(i) cout << " ";
 			if(valid(ro, col-1, n) && v[ro][col-1] == ans[i]){
 				cout << "left";
 				col = col -1;
 			}
 			else if(valid(ro, col + 1, n) && v[ro][col + 1] == ans[i]){
 				cout << "right";
 				col = col + 1;
 			}
 			else {
 				cout << "forth";
 				ro--;
 			}
 		}
 		cout << "\n";
 	}	
    return 0;
}