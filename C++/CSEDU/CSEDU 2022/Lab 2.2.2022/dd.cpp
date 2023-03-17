#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct emp {
	string name, dep, des;
};

bool compr(emp e1, emp e2) {
	if (e1.dep != e2.dep)return e1.dep < e2.dep;
	else {
		if (e1.des != e2.des) {
			if (e1.des == "MD")return true;
			else if (e1.des == "GM" && e2.des != "MD")return true;
			else if (e1.des == "DGM" && e2.des != "GM" && e2.des != "MD")return true;
			else if (e1.des == "AGM" && e2.des != "GM" && e2.des != "MD" && e2.des != "DGM")return true;
			else return false;
		} else return e1.name < e2.name;
	}
}

int main() {
	fast_io();
	int n;
	cin >> n;
	vector<emp> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].name >> a[i].dep >> a[i].des;
	}
	sort(a.begin(), a.end(), compr);
	for (int i = 0; i < n; i++) {
		cout << a[i].name << ' ' << a[i].dep << ' ' << a[i].des << "\n";
	}
	return 0;
}