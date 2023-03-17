#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, k;
 		cin >> n >> k;
 		deque<int> a, ans(n, -1);
 		for (int i=0; i<n; i++)a.push_back(i + 1);
 		for (int i=k-1; i<n; i+=k){
 			ans[i] = a.front();
 			a.pop_front();
 		}
 		for (int i=0; i<n; i++){
 			if(ans[i] == -1){
 				ans[i] = a.back();
 				a.pop_back();
 			}
 		}
 		for (int i=0; i<n; i++)cout << ans[i] << ' ';
 			cout << '\n';
 	}	
    return 0;
}