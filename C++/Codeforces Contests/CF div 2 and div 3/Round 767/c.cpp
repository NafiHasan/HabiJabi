#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define dbg(x) cout<<#x<<" = "<<x<<en
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 

int main()
{
    fast_io();
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>a(n), ans;
        for (int i=0; i<n; i++)cin >> a[i];
        int now = 0;
        while(now < n){
            int mx = 0;
            bool go = 0;
            set<int> tmp;
            for (int i = now; i < n; i++){
                tmp.insert(a[i]);
                if(*tmp.rbegin() == tmp.size() - 1)mx = max(mx, *tmp.rbegin());
            }
            // cout << "size " << tmp.size() << '\n';
            if(*tmp.rbegin() != tmp.size() - 1){
                for (int i=0; i<=n; i++){
                    if(tmp.find(i) == tmp.end()){
                        mx = i;
                        go = 1;
                        // cout << i << '\n';
                        break;
                    }
                }
            }
            tmp.clear();
            if(go){
                for (int i= now; i<n; i++){
                    tmp.insert(a[i]);
                    if(tmp.find(mx) == tmp.end()){
                        now++;
                        ans.push_back(mx);
                    }
                }
            }
            else{
                for (int i = now; i < n; i++)
                {
                    tmp.insert(a[i]);
                    if (*tmp.rbegin() == tmp.size() - 1 && *tmp.rbegin() == mx)
                    {
                        now = i + 1;
                        ans.push_back(mx + 1);
                        // cout << now << 'a';
                        break;
                    }
                }
                if (*tmp.rbegin() != tmp.size() - 1 || *tmp.rbegin() != mx)
                {
                    ans.push_back(mx + 1);
                    now = n;
                }
            }
            // cout << now << '\n';
        }
        cout << ans.size() << '\n';
        for (int i=0; i<ans.size(); i++)cout << ans[i] <<' ';
        cout << '\n'; 
    }
    return 0;
}