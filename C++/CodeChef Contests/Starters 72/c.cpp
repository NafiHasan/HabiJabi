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
 		vector<int> a(n), ans;
 		int st = -1;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			if(a[i] == 1 && ans.empty()){
 				ans.push_back(i + 1);
 				ans.push_back(i + 2);
 				st = i + 1;
 			}
 		}
 		int cnt1 = 0, cnt0 = 0;
 		if(st != -1)cnt1 =1;
 		for (int i = st; i<n; i++){
 			if(a[i] == 1)cnt1++;
 			else cnt0++;
 			if(cnt1 - cnt0 == (int)ans.size()){
 				ans.push_back(i + 2);
 			}
 		}
 		if(ans.size() ==0){
 			cout << "1\n1\n";
 			continue;
 		}
 		cout << ans.size() << '\n';
 		for (int i=0; i<ans.size(); i++)cout << ans[i] << ' ';
 		cout<< '\n';
 	}	
    return 0;
}