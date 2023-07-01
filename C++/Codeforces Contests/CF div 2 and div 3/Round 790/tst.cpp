//Don't forget to clear the global variables
// make sure to set the maximum size according to the problem

const int N = 3e5 + 10;

vector<int> par(N), rnk(N, 0), siz(N, 1);

void makeset() {
	for (int i = 1; i < N; i++)par[i] = i;
}

int get(int a) {
	// path compressed, change if needed
	return (par[a] == a ? a : (par[a] = get(par[a])));
}

void union_set(int a, int b) {
	a = get(a);  // find the topmost parent
	b = get(b);

	if (a == b)return; // are in same set

	if (rnk[a] == rnk[b])rnk[a]++;

	if (rnk[a] > rnk[b])par[b] = a;
	else par[a] = b;
}

void clr() {
	makeset();
	par.clear();
	rnk.clear();
	siz.clear();
}
