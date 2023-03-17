#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int sum = 0, mask = 128;
	vector<int> all;
	map<tuple<int, int, int>, int> mp, mp2, mp3, mp4, mp5;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k =  1; k <= 100; k++) {
				if (i + j + k < 0 || (i + j + k) % 2 == 0 || i == j || j == k || i == k || i == 90 || j == 90 || k == 90 || i == 4 || j == 4 || k == 4 || i == 3 || j == 3 || k == 3)continue;
				all.clear();
				all.push_back(i);
				all.push_back(j);
				all.push_back(k);
				all.push_back(90);
				all.push_back(3);
				all.push_back(4);
				sum = i + j + k + 97;
				sum /= 2;
				for (int m = 1; m <= 64; m++) {
					int tmp = 0;
					for (int l = 0; l < 6; l++) {
						if (((1 << l) & m) != 0)tmp += all[l];
					}
					if (tmp == sum ) {
						// cout << i << ' ' << j << ' ' << k << '\n';
						mp[ {i, j, k}]++;
						// if (mp[ {i, j, k}] > 1)cout << i << ' ' << j << ' ' << k << " same\n";
						// break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k =  1; k <= 100; k++) {
				if (i + j + k < 0 || (i + j + k) % 2 == 0 || i == j || j == k || i == k || i == 86 || j == 86 || k == 86 || i == 8 || j == 8 || k == 8 || i == 9 || j == 9 || k == 9)continue;
				all.clear();
				all.push_back(i);
				all.push_back(j);
				all.push_back(k);
				all.push_back(86);
				all.push_back(8);
				all.push_back(9);
				sum = i + j + k + 103;
				sum /= 2;
				for (int m = 1; m <= 64; m++) {
					int tmp = 0;
					for (int l = 0; l < 6; l++) {
						if (((1 << l) & m) != 0)tmp += all[l];
					}
					if (tmp == sum ) {
						// cout << i << ' ' << j << ' ' << k << '\n';
						mp4[ {i, j, k}]++;
						// if (mp[ {i, j, k}] > 1)cout << i << ' ' << j << ' ' << k << " same\n";
						// break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k =  1; k <= 100; k++) {
				if (i + j + k < 0 || (i + j + k) % 2 == 0 || i == j || j == k || i == k || i == 57 || j == 57 || k == 57 || i == 87 || j == 87 || k == 87 || i == 89 || j == 89 || k == 89)continue;
				all.clear();
				all.push_back(i);
				all.push_back(j);
				all.push_back(k);
				all.push_back(57);
				all.push_back(87);
				all.push_back(89);
				sum = i + j + k + 233;
				sum /= 2;
				for (int m = 1; m <= 64; m++) {
					int tmp = 0;
					for (int l = 0; l < 6; l++) {
						if (((1 << l) & m) != 0)tmp += all[l];
					}
					if (tmp == sum ) {
						// cout << i << ' ' << j << ' ' << k << '\n';
						mp3[ {i, j, k}]++;
						// if (mp[ {i, j, k}] > 1)cout << i << ' ' << j << ' ' << k << " same\n";
						// break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = i + 1; j <= 100; j++) {
			for (int k = j + 1; k <= 100; k++) {
				if (i + j + k < 0 || (i + j + k) % 2 == 0 || i == j || j == k || i == k || i == 7 || j == 7 || k == 7 || i == 77 || j == 77 || k == 77 || i == 9 || j == 9 || k == 9)continue;
				all.clear();
				all.push_back(i);
				all.push_back(j);
				all.push_back(k);
				all.push_back(7);
				all.push_back(77);
				all.push_back(9);
				sum = i + j + k + 93;
				sum /= 2;
				for (int m = 1; m <= 64; m++) {
					int tmp = 0;
					for (int l = 0; l < 6; l++) {
						if (((1 << l) & m) != 0)tmp += all[l];
					}
					if (tmp == sum ) {
						// cout << i << ' ' << j << ' ' << k << '\n';
						mp5[ {i, j, k}]++;
						// if (mp[ {i, j, k}] > 1)cout << i << ' ' << j << ' ' << k << " same\n";
						// break;
					}
				}
			}
		}
	}
	all.clear();
	for (int i = 1; i <= 100; i++) {
		for (int j =  1; j <= 100; j++) {
			for (int k = 1; k <= 100; k++) {
				if (i + j + k < 0 || (i + j + k) % 2 == 0 || i == j || j == k || i == k || i == 7 || j == 7 || k == 7 || i == 8 || j == 8 || k == 8 || i == 10 || j == 10 || k == 10)continue;
				all.clear();
				all.push_back(i);
				all.push_back(j);
				all.push_back(k);
				all.push_back(7);
				all.push_back(8);
				all.push_back(10);
				sum = i + j + k + 25;
				sum /= 2;
				for (int m = 1; m <= 64; m++) {
					int tmp = 0;
					for (int l = 0; l < 6; l++) {
						if (((1 << l) & m) != 0)tmp += all[l];
					}
					if (tmp == sum ) {
						mp2[ {i, j, k}]++;

						if (mp5[ {i, j, k}] > 0 && mp4[ {i, j, k}] > 0 && mp3[ {i, j, k}] > 0 && mp2[ {i, j, k}] >= 1 && mp[ {i, j, k}] > 0)cout << i << ' ' << j << ' ' << k << '\n';
						// break;
					}
				}
			}
		}
	}
	cout << "f";
	return 0;
}