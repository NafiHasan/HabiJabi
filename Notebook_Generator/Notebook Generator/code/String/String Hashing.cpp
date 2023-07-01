ll bigmod(ll x, ll p, ll md) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * x % md;
		x = x * x % md;
		p >>= 1;
	}
	return res;
}
ll modinv(ll x, ll md) {
	return bigmod(x, md - 2, md);
}
namespace Hash {
ll pw[M][2];
ll invpw[M][2];
const int pr[] = {37, 53};
const int md[] = {1000000007, 1000000009};
void precalc() {
	pw[0][0] = pw[0][1] = 1;
	for (int i = 1; i < M; i++) {
		pw[i][0] = pw[i - 1][0] * pr[0] % md[0];
		pw[i][1] = pw[i - 1][1] * pr[1] % md[1];
	}
	invpw[M - 1][0] = modinv(pw[M - 1][0], md[0]);
	invpw[M - 1][1] = modinv(pw[M - 1][1], md[1]);
	for (int i = M - 2; i >= 0; i--) {
		invpw[i][0] = invpw[i + 1][0] * pr[0] % md[0];
		invpw[i][1] = invpw[i + 1][1] * pr[1] % md[1];
	}
}
pii get_hash(const string &s) {
	pii ret = {0, 0};
	for (int i = 0; i < s.size(); i++) {
		ret.first += (s[i] - 'a' + 1) * pw[i][0] % md[0];
		ret.second += (s[i] - 'a' + 1) * pw[i][1] % md[1];
		if (ret.first >= md[0]) ret.first -= md[0];
		if (ret.second >= md[1]) ret.second -= md[1];
	}
	return ret;
}
void prefix(const string &s, pii *H) {
	H[0] = {0, 0};
	for (int i = 1; i <= s.size(); i++) {
		H[i].first = H[i - 1].first + (s[i - 1] - 'a' + 1) * pw[i - 1][0] % md[0];
		H[i].second = H[i - 1].second + (s[i - 1] - 'a' + 1) * pw[i - 1][1] % md[1];
		if (H[i].first >= md[0]) H[i].first -= md[0];
		if (H[i].second >= md[1]) H[i].second -= md[1];
	}
}
void reverse_prefix(const string &s, pii *H) {
	int n = s.size();
	for (int i = 1; i <= s.size(); i++) {
		H[i].first = H[i - 1].first + (s[i - 1] - 'a' + 1) * pw[n - i][0] % md[0];
		H[i].second = H[i - 1].second + (s[i - 1] - 'a' + 1) * pw[n - i][1] % md[1];
		if (H[i].first >= md[0]) H[i].first -= md[0];
		if (H[i].second >= md[1]) H[i].second -= md[1];
	}
}
pii range_hash(int L, int R, pii H[]) {
	pii ret;
	ret.first = (H[R].first - H[L - 1].first + md[0]) % md[0];
	ret.second = (H[R].second - H[L - 1].second + md[1]) % md[1];
	ret.first = ret.first * invpw[L - 1][0] % md[0];
	ret.second = ret.second * invpw[L - 1][1] % md[1];
	return ret;
}
pii reverse_hash(int L, int R, pii H[], int n) {
	pii ret;
	ret.first = (H[R].first - H[L - 1].first + md[0]) % md[0];
	ret.second = (H[R].second - H[L - 1].second + md[1]) % md[1];
	ret.first = ret.first * invpw[n - R][0] % md[0];
	ret.second = ret.second * invpw[n - R][1] % md[1];
	return ret;
}
}