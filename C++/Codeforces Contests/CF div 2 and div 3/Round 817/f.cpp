#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// dfs on a grid
const int N = 55;
int n, m; // row, column

vector<string> grid(N);
vector<vector<bool>> vis(N, vector<bool> (N));

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dr2[] = {-1, 0, 1, 0};
int dc2[] = {0, -1, 0, 1};

bool valid(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m)return 0;
	if (grid[r][c] == '.')return 0; // checking block
	return 1;
}

int cnt = 0;
vector<pair<int,int>> cells;
void dfs(int r, int c) {
	vis[r][c] = 1;
	cnt++;
	cells.push_back({r, c});

	for (int i = 0; i < 8; i++) {
		int rr = r + dr[i], cc = c + dc[i];
		if (valid(rr, cc) && !vis[rr][cc]) {
			dfs(rr, cc);
		}
	}
}

void dfs2(int r, int c){
	vis[r][c] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int rr = r + dr2[i], cc = c + dc2[i];
		if (valid(rr, cc) && !vis[rr][cc]) {
			dfs2(rr, cc);
		}
	}
}


void clear_vis(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			vis[i][j] = 0;
}



int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		cin >> n >> m;
 		clear_vis();
 		for (int i=0; i<n; i++)cin >> grid[i];
 		bool ans = 1;
 		for (int i=0; i<n && ans; i++){
 			for (int j=0; j<m && ans; j++){
 				if(grid[i][j] == '*' && !vis[i][j]){
 					cnt = 0;
 					cells.clear();
 					dfs(i, j);
 					if(cnt != 3){
 						ans = 0;
 					}
 					if(cnt == 3){
 						if(cells[0].first == cells[1].first && cells[1].first == cells[2].first)ans = 0;
 						if(cells[0].second == cells[1].second && cells[1].second == cells[2].second)ans = 0;
 					}
 					if(ans){
 						vis[cells[0].first][cells[0].second] = 0;
 						vis[cells[1].first][cells[1].second] = 0;
 						vis[cells[2].first][cells[2].second] = 0;
 						cnt = 0;
 						dfs2(cells[0].first, cells[0].second);
 						if(cnt != 3)ans = 0;
 					}
 				}
 			}
 		}
 		if(ans)cout << "YES\n";
 		else cout << "NO\n";
 	}
    return 0;
}