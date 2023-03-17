#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;

		vector<int> edge[n + 5];

		for (int i=0; i<n; i++){
			edge[i + 1].push_back(i + 1);
			string s;
			cin >> s;
			for (int j=0; j<n; j++){
				if(s[j] == '1') edge[j + 1].push_back(i + 1);
			}
		}

		for (int i=1; i<=n; i++){
			cout << edge[i].size() << ' ';
			for (auto x : edge[i])cout << x << ' ' ;
			cout << '\n';
		}
	}	
    return 0;
}