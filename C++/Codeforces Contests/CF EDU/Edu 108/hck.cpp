#include <stdio.h>
typedef long long ll;
ll n, t;
ll r, b, d;
ll abs(ll x) {
    return x > 0 ? x : -x;
}
ll min(ll x, ll y) {
    return x < y ? x : y;
}

int main() {
    scanf("%lld", &t);
    while (t--) {
        //scanf("%lld",&n);
        scanf("%d%d%d", &r, &b, &d);
        if (abs(r - b) <= min(r, b)*d) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
