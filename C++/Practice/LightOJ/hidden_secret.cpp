#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	// FastIO;
	int tc;
	cin >> tc;
	getchar();
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case " << cs << ": ";
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] >= 'A' && s1[i] <= 'Z') {
				s1[i] += 32;
			}
		}
		for (int i = 0; i < s2.size(); i++) {
			if (s2[i] >= 'A' && s2[i] <= 'Z') {
				s2[i] += 32;
			}
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		while (s1.back() == ' ')s1.pop_back();
		while (s2.back() == ' ')s2.pop_back();
		if (s1 == s2)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}