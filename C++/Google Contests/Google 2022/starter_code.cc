#include <bits/stdc++.h>
using namespace std;

int GetMinimumNumberOfComplaints(vector<string> friend_orders,
                                 vector<string> forbidden_orders, int options) {
  int minimum_number_of_complaints = 0;
  return minimum_number_of_complaints;
}

int main() {
  int t;
  // 't' refers to number of test cases.
  cin >> t;
  for (int tc = 1; tc <= t; ++tc) {
    // 'n' refers to preferences of friends.
    // 'm' refers to number of prohibited milk teas.
    // 'p' refers to binary options available at the tea shop.
    int n, m, p;
    cin >> n;
    cin >> m;
    cin >> p;
    vector<string> friend_orders(n);
    vector<string> forbidden_orders(m);
    for (int i = 0; i < n; ++i) {
      cin >> friend_orders[i];
    }
    for (int i = 0; i < m; ++i) {
      cin >> forbidden_orders[i];
    }
    cout << "Case #" << tc << ": "
         << GetMinimumNumberOfComplaints(friend_orders, forbidden_orders, p)
         << endl;
  }
  return 0;
}
