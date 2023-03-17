#include<bits/stdc++.h>
using namespace std;

// int MAX = 86030000;
// int prime[86030005];
vector<int>primes;

void seive() {
  const int N = 86030000;
  vector<int> lp(N + 1);

  for (int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int)primes.size() && primes[j] <= lp[i] && i * primes[j] <= N; ++j) {
      lp[i * primes[j]] = primes[j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  seive();

  // cout << primes.size() << '\n';
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << primes[--n] << "\n";
  }
  return 0;
}