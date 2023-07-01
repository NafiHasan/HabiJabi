#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int p;
    for (int i = 0; i < n; i++) {
        if (m < a[i]) {
            p = i;
            break;
        } else {
            if (k == 0)
                p = 0;
            else {
                p = n;
            }
        }
    }
    int pp = n - p;
    if (pp <= k) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}