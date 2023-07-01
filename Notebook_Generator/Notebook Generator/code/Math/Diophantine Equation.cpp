int gcd_extend(int a, int b, int& x, int& y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int g = gcd_extend(b, a % b, x, y);
		int x1 = x, y1 = y;
		x = y1;
		y = x1 - (a / b) * y1;
		return g;
	}
}
void print_solution(int a, int b, int c) {
	int x, y;
	if (a == 0 && b == 0) {
		if (c == 0) {
			cout << "Infinite Solutions Exist" << endl;
		}
		else {
			cout << "No Solution exists" << endl;
		}
	}
	int gcd = gcd_extend(a, b, x, y);
	if (c % gcd != 0) {
		cout << "No Solution exists" << endl;
	}
	else {
		cout << "x = " << x * (c / gcd) << ", y = " << y * (c / gcd) << endl;
	}
}