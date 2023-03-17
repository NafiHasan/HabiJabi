#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tests;
	cin >> tests;
	for (int test_case = 1; test_case <= tests; test_case++) {
		int paper_count;
		cin >> paper_count;
		vector<int> answer(paper_count);
		multiset<int> ms;
		int best = 0;
		for (int i = 0; i < paper_count; i++) {
			int x;
			cin >> x;
			if (x > best)ms.insert(x);
			best = max(best, (int)ms.size());
			while (!ms.empty() && *ms.begin() <= best)ms.erase(*ms.begin());
			answer[i] = best;
		}
		cout << "Case #" << test_case << ": ";
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << endl;
	}
	return 0;
}