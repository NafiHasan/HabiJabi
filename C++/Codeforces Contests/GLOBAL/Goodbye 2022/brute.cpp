/**
 *    author:  tourist
 *    created: 30.12.2022 18:43:35       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] == a[j]) {
          ok = false;
        }
      }
    }
    for (int p = 2; p <= n; p++) {
      vector<int> cnt(p);
      for (int i = 0; i < n; i++) {
        cnt[a[i] % p] += 1;
      }
      cout << cnt[0] << '\n';
      if (*min_element(cnt.begin(), cnt.end()) >= 2) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
