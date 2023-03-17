#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	string s,t, ns = "", nt = "";
 	cin >> s >> t;
 	map<char, int> cnt;
 	vector<int> vs, vt;
 	for (int i =0; i<(int)s.size(); i++){
 		if(i && s[i] == s[i - 1]){
 			cnt[s[i]]++;
 		}
 		else if(i && s[i] != s[i - 1]){
 			vs.push_back(cnt[s[i - 1]]);
 			cnt.clear();
 			cnt[s[i]]++;
 			ns += s[i];
 		}
 		else {
 			ns += s[i];
 			cnt[s[i]]++;
 		}
 		if(i == (int)s.size() - 1){
 			vs.push_back(cnt[s[i]]);
 		}
 	}
 	cnt.clear();
 	for (int i =0; i<(int)t.size(); i++){
 		if(i && t[i] == t[i - 1]){
 			cnt[t[i]]++;
 		}
 		else if(i && t[i] != t[i - 1]){
 			vt.push_back(cnt[t[i - 1]]);
 			cnt.clear();
 			cnt[t[i]]++;
 			nt += t[i];
 		}
 		else {
 			nt += t[i];
 			cnt[t[i]]++;
 		}
 		if(i == (int)t.size() - 1){
 			vt.push_back(cnt[t[i]]);
 		}
 	}
 	// cout << ns << '\n' << nt << '\n';
 	if(ns != nt){
 		cout << "No\n";
 		return 0;
 	} 
 	bool ok = 1;
 	for (int i=0; i<vs.size(); i++){
 		if(vs[i] == 1 && vt[i] > 1)ok = 0;
 		if(vs[i] > vt[i])ok = 0;
 		// cout << vs[i] << ' ' << vt[i] << '\n';
 	}
 	if(ok)cout << "Yes\n";
 	else cout << "No\n";
    return 0;
}