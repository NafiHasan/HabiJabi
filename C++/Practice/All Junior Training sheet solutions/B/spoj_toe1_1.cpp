#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	while (n--) {
		vector<vector<char>> v(4, vector<char> (4));
		int cntx = 0, cnto = 0;
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> v[i][j];
				if (v[i][j] == 'X')cntx++;
				else if (v[i][j] == 'O')cnto++;
			}
		}
		if (cntx < cnto || cntx - cnto > 1) {
			cout << "no\n";
			continue;
		}
		int cnt = 0, cnx = 0, cno = 0;
		//horizontal
		bool ys = 1;
		for (int j = 1; j <= 3; j++) {
			if (v[1][1] == '.')ys = 0;
			if (v[1][j] != v[1][1])ys = 0;
		}
		if (ys) {
			cnt++;
			if (v[1][1] == 'X')cnx++;
			else cno++;
		}
		ys = 1;
		for (int j = 1; j <= 3; j++) {
			if (v[2][1] == '.')ys = 0;
			if (v[2][j] != v[2][1])ys = 0;
		}
		if (ys) {
			cnt++;
			if (v[2][1] == 'X')cnx++;
			else cno++;
		}
		// if (ys)cnt3++;
		ys = 1;
		for (int j = 1; j <= 3; j++) {
			if (v[3][1] == '.')ys = 0;
			if (v[3][j] != v[3][1])ys = 0;
		}
		if (ys) {
			cnt++;
			if (v[3][1] == 'X')cnx++;
			else cno++;
		}
		//corner
		ys = 1;
		for (int i = 1; i <= 3; i++) {
			if (v[1][1] == '.')ys = 0;
			if (v[i][i] != v[1][1])ys = 0;
		}
		if (ys) {
			cnt++;
			if (v[1][1] == 'X')cnx++;
			else cno++;
		}
		// if (ys)cnt2++;
		ys = 1;
		for (int i = 1, j = 3; i <= 3; i++, j--) {
			if (v[1][3] == '.')ys = 0;
			if (v[i][j] != v[1][3])ys = 0;
		}
		if (ys) {
			cnt++;
			if (v[1][3] == 'X')cnx++;
			else cno++;
		}
		// if (ys)cnt2++;
		ys = 1;
		for (int j = 1; j <= 3; j++) {
			if (v[1][1] == '.')ys = 0;
			if (v[j][1] != v[1][1])ys = 0;
		}
		if (ys) {
			cnt++;
			if (v[1][1] == 'X')cnx++;
			else cno++;
		}
		ys = 1;
		for (int j = 1; j <= 3; j++) {
			if (v[1][2] == '.')ys = 0;
			if (v[j][2] != v[1][2])ys = 0;
		}
		if (ys) {
			cnt++;
			if (v[1][2] == 'X')cnx++;
			else cno++;
		}
		// if (ys)cnt3++;
		ys = 1;
		for (int j = 1; j <= 3; j++) {
			if (v[1][3] == '.')ys = 0;
			if (v[j][3] != v[1][3])ys = 0;
		}
		if (ys) {
			cnt++;
			if (v[1][3] == 'X')cnx++;
			else cno++;
		}
		if (cnt == 2 && cntx == 5 && cnto == 4 && cnx == 2)cout << "yes\n";
		// // if (cnt == 2 && cnt2 == 2)cout << "yes\n";
		// // else if (cnt == 2 && cnt3 == 2)cout << "yes\n";
		else if (cnt > 1)cout << "no\n";
		else if (cnt == 1 && cntx > cnto && cno == 1)cout << "no\n";
		else if (cnt == 1 && cnto == cntx && cnx == 1)cout << "no\n";
		else cout << "yes\n";
	}
	return 0;
}