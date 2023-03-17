#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

 	int n, t;
 	cin >> n>> t;

 	vector<vector<int>> info(n + 5, vector<int> (4));
 	for (int i=0; i<n; i++){
 		for (int j=0; j<4; j++){
 			cin >> info[i][j];
 		}
 	}

 	int m;
 	cin >> m;
 	deque<pair<string, int>> words;
 	for (int i=0; i<m; i++){
 		string s; int comp;
 		cin >> s >> comp;
 		words.push_back({s, comp});
 	}

 	int ind = 0;
 	map<pair<int,string>, int> d;
 	vector<string> ans[n + 1];
 	int rem = t;
 	while(words.size() > 0){
 		pair<string, int> tp = words.front();
 		words.pop_front();
 		int need = max(1, tp.second - d[{ind % n, tp.first}] - ((ind / n) % 2 ? (info[ind % n][1] + info[ind % n][2]) : (info[ind % n][0] + info[ind % n][3])));
 		if(need <= rem){
 			rem -= need;
 			ans[ind % n].push_back(tp.first);
 			if(rem == 0){
 				rem = t;
 				ind++;
 			}
 		}
 		else {
 			d[{ind % n, tp.first}] += rem;
 			rem = t;
 			ind++;
 			words.push_back(tp);
 		}
 	}
 	for (int i=0; i<n; i++){
 		cout << ans[i].size() << ' ';
 		for (int j=0; j<ans[i].size(); j++){
 			cout << ans[i][j] << ' ';
 		}
 		cout << '\n';
 	}
    return 0;
}