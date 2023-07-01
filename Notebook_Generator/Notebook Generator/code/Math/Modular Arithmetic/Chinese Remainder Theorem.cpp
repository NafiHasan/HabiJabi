/*** X = a_1 % m_1
X = a_2 % m_2
X = a_3 % m_3
m_1,m_2,m_3 are pair wise co-prime
M = m_1*m_2*m_3
u_i = Modular inverse of (M/m_i) with respect m_i
X = ( a_1 * (M/m_1) * u_1 + a_2 * (M/m_2) * u_2 + a_3 * (M/m_3) * u_3 ) % M ***/
ll inv(ll a, ll m) {
	ll m0 = m, t, q;
	ll x0 = 0, x1 = 1;
	if (m == 1) return 0;
	while (a > 1) {
		q = a / m; t = m; m = a % m, a = t; t = x0; x0 = x1 - q * x0; x1 = t;
	}
	if (x1 < 0) x1 += m0;
	return x1;
}
ll findMinX(ll num[], ll rem[], ll k) {
	ll prod = 1;
	for (ll i = 0; i < k; i++) prod *= num[i];
	ll result = 0;
	for (ll i = 0; i < k; i++) {
		ll pp = prod / num[i];
		result += rem[i] * inv(pp, num[i]) * pp;
	}
	return result % prod;
}
int main() {
	ll num[15], rem[15], n, t, i, j;
	scanf("%lld", &t);
	for (i = 1; i <= t; i++) {
		scanf("%lld", &n);
		for (j = 0; j < n; j++)
			scanf("%lld %lld", &num[j], &rem[j]);
		printf("Case %lld: %lld\n", i, findMinX(num, rem, n));
	}
}