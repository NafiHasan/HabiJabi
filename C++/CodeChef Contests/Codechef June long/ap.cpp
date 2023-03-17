#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<long long> > a(n, vector<long long>(m, 0));
		int ro = 1, col = 2;
		a[0][0] = 1;
		if(n > m)swap(ro, col);
		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if(j == 0 && i){
					
				}
			}
		}
	}
	return 0;
}