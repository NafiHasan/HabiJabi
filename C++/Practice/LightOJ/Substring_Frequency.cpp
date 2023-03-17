#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 1000005;
string s, pat; 
//s = given string, pat = pattern to match

int n, m, cnt = 0;
//n = s.size(), m = pat.size()

vector<int> lps(N, 0);  
//lps[i] = longest common prefix which is also a suffix of the range 0...i

//calculate lps
void prefun() {
	int i = 0, j = -1;
	lps[0] = -1;

	while (i < m) {
		while (j >= 0 && pat[i] != pat[j])j = lps[j];
		//while there is a mismatch, set index j to last longest match

		i++; j++;  // if there is a match, increase both i and j
		lps[i] = j;
	}
}

vector<int> kmpSearch() {
	vector<int> ind;
	// holds position of the starting of each matching substring

	cnt = 0;
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && s[i] != pat[j])j = lps[j];
		// same as creating prefun

		i++, j++;
		if (j == m) { // matched the full pattern 
			ind.push_back(i - j);
			j = lps[j];// no need to go to index 0, just move the last longest matched pattern. 
		}
	}
	return ind;
}

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	for (int cs = 1; cs <= tc; cs++){
 		cout << "Case " << cs << ": ";

 		cin >> s >> pat;
 		n = s.size(), m = pat.size();
 		fill(lps.begin(), lps.end(), 0);
 		prefun();

 		vector<int> ans = kmpSearch();
 		cout << ans.size() << '\n';
 	}
    return 0;
}