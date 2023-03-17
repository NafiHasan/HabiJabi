#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	string s;
	int day1, day2, h1, h2, m1, m2, s1, s2;
	cin >> s >> day1 >> h1 >> s >> m1 >> s >> s1;
	cin >> s >> day2 >> h2 >> s >> m2 >> s >> s2;
	int sec = 0;
	if (s1 > s2) {
		s2 += 60;
		m2--;
		if (m2 < 0) {
			m2 = 59;
			h2--;
			if (h2 < 0) {
				h2 = 23;
				day2--;
			}
		}
	}
	if (m1 > m2) {
		m2 += 60;
		h2--;
		if (h2 < 0) {
			h2 = 23;
			day2--;
		}
	}
	if (h1 > h2) {
		h2 += 24;
		day2--;
	}
	cout << day2 - day1 << " day(s)\n";
	cout << h2 - h1 << " hour(s)\n";
	cout << m2 - m1 << " minute(s)\n";
	cout << s2 - s1 << " second(s)\n";
	return 0;
}