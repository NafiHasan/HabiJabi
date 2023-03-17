#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, k;
 		string s;
 		cin >> n >> k >> s;
 		int cnt = 0, ans = n + 5;
 		vector<int> op(n + 4, 0);
 		for (int i= n - 1, j = 0; j < k; i--, j++){
 			if(s[i] == '1'){
 				if(cnt % 2){
 					cnt++;
 				}
 				// op[i] = 1;
 			}
 			else {
 				if(cnt % 2 == 0){
 					cnt++;
 				}
 			}
 		}
 		ans = cnt;
 		for (int i= n - 2; i - k + 1 >= 0 ; i--){
 			int tmp = cnt;
 			if(s[i + 1] == '0' && s[i] == '1')tmp -= 2;
 			if(s[i - k + 1] == '0' && cnt % 2 == 0){
 				tmp++;
 			}
 			else if(s[i - k + 1] == '1' && cnt % 2 == 1){
 				tmp++;
 			}
 			cnt = tmp;
 			ans = min(ans, cnt);
 			// cout << s.substr(i - k + 1, k) << '\n';
 			// cout << cnt << '\n';
 		}
 		cout << ans << '\n';
 	}	
    return 0;
}