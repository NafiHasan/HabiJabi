#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



vector<int> rabinKarp(string giv, string pat){
	const int p = 31; // take 53 if both upper and lower exist
	const int mod = 1e9 + 9;

	int G = giv.size(), P = pat.size();

	vector<long long> p_pow(max(G, P), 1LL);

	// precalculating powers 
	for (int i = 1; i < (int)p_pow.size(); i++)
		p_pow[i] = (p_pow[i - 1] * p) % mod;

	vector<long long> hashes(G + 1, 0);

	// calculating hash of every prefix of the given string
	for (int i=0; i<G; i++)
		hashes[i + 1] = (hashes[i] + (giv[i] - 'a' + 1) * p_pow[i]) % mod;

	long long patHash = 0;
	for (int i=0; i<P; i++)
		patHash = (patHash + (pat[i] - 'a' + 1) * p_pow[i]) % mod;

	vector<int> ind;
	// contains all the occurences of the matches

	for (int i=0; i + P - 1 < G; i++){
		long long curHash = (hashes[i + P] + mod - hashes[i]) % mod; // taking hash value of length P of given string starting from index i

		if(curHash == patHash * p_pow[i] % mod) 
			ind.push_back(i);
		// multiplying p_pow[i] to match the indexes.
	}

	return ind;
}



int main() {
	FastIO;
	int tc;
 	cin >> tc;
 	for (int cs = 1; cs <= tc; cs++){
 		cout << "Case " << cs << ": ";

 		string s, pat;
 		cin >> s >> pat;

 		vector<int> ans = rabinKarp(s, pat);
 		cout << (int)ans.size() << '\n';
 	} 		
    return 0;
}