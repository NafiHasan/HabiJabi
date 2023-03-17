#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		string s1, s2;
 		cin >> s1;
 		s2 = s1;
 		reverse(s2.begin(), s2.end());
 		int L[n + 1][n + 1];
 		int ans = 0;
 		for (int i = 0; i <= n; i++){
 			for (int j = 0; j <= n; j++){
 				if (i == 0 || j == 0)
 					L[i][j] = 0;

 				else if (s1[i - 1] == s2[j - 1])
 					L[i][j] = L[i - 1][j - 1] + 1;

 				else{
 					L[i][j] = max(L[i - 1][j], L[i][j - 1]);
 					// ans = max(ans, L[i][j]);
 				}
 			}
 		}
 		for (int i=0; i<=n; i++){
 			for (int j=0; j<=n; j++){
 				if(i + j <= n)ans = max(ans, L[i][j]);
 			}
 		}
 		cout << ans << '\n';
 	}
    return 0;
}