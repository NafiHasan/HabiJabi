#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string GetRuler(const string& kingdom) {
	// TODO: implement this method to determine the ruler name, given the kingdom.
	string ruler = "";
	char c = kingdom.back();
	if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'U' || c == 'u' || c == 'O' || c == 'o')ruler = "Alice";
	else if (c == 'Y' || c == 'y')ruler = "nobody";
	else ruler = "Bob";
	return ruler;
}

int main() {
	fast_io();
	int testcases;
	cin >> testcases;
	string kingdom;

	for (int t = 1; t <= testcases; ++t) {
		cin >> kingdom;
		cout << "Case #" << t << ": " << kingdom << " is ruled by "
		     << GetRuler(kingdom) << ".\n";
	}
	return 0;
}

