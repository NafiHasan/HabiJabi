#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	// fast_io();
	string s1, s2;
 	while(1){
 		cin >> s1 >> s2;
 		if(feof(stdin))break;
 		string ans = "";
 		vector<string> v;
 		int n1 = s1.size(), n2 = s2.size();
 		int add =0;
 		for (int i=n1-1; i >= 0; i--){
 			int num1 = s1[i] - '0';
 			string tmp;
 			for (int j = n2-1; j>=0; j--){
 				int num2 = s2[j] - '0';
 				int a = num1 * num2 + add;
 				add = 0;
 				if(a > 9){
 					add = a / 10;
 					a = a % 10;
 				} 
 				tmp += a + '0';
 			}
 			if(add > 0){
 				tmp += to_string(add);
 				add = 0;
 			}
 			reverse(tmp.begin(), tmp.end());
 			for (int j=0; j<v.size(); j++)tmp += '0';
 			reverse(tmp.begin(), tmp.end());
 			v.push_back(tmp);
 		}
 		int car = 0;
 		for (int i=0; i<3000; i++){
 			int ad = car;
 			bool ys = 0;
 			for (int j= 0; j<v.size(); j++){
 				if(i < v[j].size()){
 					ad += v[j][i] - '0';
 					ys = 1;
 				}
 			}
 			if(ys){
 				car = 0;
 				if(ad > 9){
 					car = ad/10;
 					ad = ad % 10;
 				}
				ans += ad + '0';
 			}
 		}
 		if(car > 0)ans += to_string(car);
 		reverse(ans.begin(), ans.end());
 		int ind = ans.size() - 1;
 		for (int i=0; i<ans.size(); i++){
 			if(ans[i] != '0'){
 				ind = i;
 				break;
 			}
 		}
 		for (int i=ind; i<ans.size(); i++)cout << ans[i];
 		cout << '\n';
 	}	
    return 0;
}