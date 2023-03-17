
const double eps = 1e-9;
double ternary_search(double l, double r) {
	while (r - l > eps) {
		double m1 = l + (r - l) / 3.0;
		double m2 = r - (r - l) / 3.0;
		if (m1 < m2) {
			l = m1;
		} else {
			r = m2;
		}
	}
	return l;
}


int ts(int l, int r) {
	while (l < r) {
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;
		if (m1 < m2) {
			l = m1;
		} else {
			r = m2;
		}
	}
	return l;
}