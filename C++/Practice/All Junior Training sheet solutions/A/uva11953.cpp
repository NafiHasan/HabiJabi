#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int N = 200;
vector<string> v(N);
bool fo = 0;

bool valid(int ro, int col, int n){
	if(ro >= n || col >= n)return 0;
	return 1;
}

void dfs(int ro, int col, int n, char c){
	if(v[ro][col] == 'x')fo = 1;
	v[ro][col] = '.';
	if(c == 'r'){
		if(valid(ro, col + 1, n) && v[ro][col + 1] != '.')dfs(ro,col + 1, n, 'r');
	}
	else {
		if(valid(ro + 1, col, n) && v[ro+1][col] != '.')dfs(ro+1,col, n, 'l');
	}
}


int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	int cs = 1;
 	while(tc--){
 		int n;
 		cin >> n;
 		for (int i=0; i<n; i++)cin >> v[i];
 		int ans = 0;
 		for (int i=0; i<n; i++){
 			for (int j=0; j<n; j++){
 				if(v[i][j] == '.')continue;
 				if(v[i][j] == 'x')fo = 1;
 				else fo = 0;
 				if(valid(i, j+1, n) && v[i][j+1] != '.') dfs(i, j+1, n, 'r');
 				if(valid(i+1,j,n) && v[i+1][j] != '.') dfs(i+1,j,n,'l');
 				if(fo)ans++;
 			}
 		}
 		cout << "Case " << cs++ << ": " << ans << "\n"
 		;
 	}	
    return 0;
}