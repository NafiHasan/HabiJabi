#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >>n;
    int a[n], cnt[8];
    memset(cnt,0, sizeof(cnt));
    for (int i=0; i<n; i++){
      cin >> a[i];
      cnt[a[i]]++;
    }
    vector<int>v;
    while(cnt[1]){
        if (cnt[2] && cnt[4]){
            v.push_back(1);
            v.push_back(2);
            v.push_back(4);
            cnt[2]--;
            cnt[1]--;
            cnt[4]--;
        }
        else if (cnt[3] && cnt[6]){
          v.push_back(1);
          v.push_back(3);
          v.push_back(6);
          cnt[3]--;
          cnt[1]--;
          cnt[6]--;
        }
        else if (cnt[2] && cnt[6]){
          v.push_back(1);
          v.push_back(2);
          v.push_back(6);
          cnt[2]--;
          cnt[1]--;
          cnt[6]--;
        }
        else break;
    }
    bool ans=1;
    for (int i=1; i<8; i++){
        if (cnt[i]){
            ans=0;
            break;
        }
    }
    if (ans && v.size()==n){
        for (int i=0; i<n; i++){
            if (i && i%3==0)cout << en;
            cout << v[i]<< " ";
        }
    }
    else cout << "-1\n";
    return 0;
}