#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	 	int tc;
 	 	cin >> tc;
 	 	cout << tc << '\n';
 	 	while(tc--){
 	 		long long aaa, sss;
 	 		cin >> aaa >> sss;
 	 		string a = to_string(aaa), s = to_string(sss);
 	 		string b = "";
 	 		// cout << a.size() << ' ' << s << '\n';
 	 		int ss = s.size();
 	 		int aa = a.size();
 	 		int dif = ss - aa;
 	 		reverse(a.begin(), a.end());
 	 		// cout << a << '\n';
 	 		for (int i=1; i<=dif ; i++) a += "0";
 	 		reverse(a.begin(), a.end());
 	 		// cout << a << '\n';
 	 		for (int i= ss - 1, j = ss - 1; i>=0, j>=0; j--,i--){
 	 			int num = s[i] - '0';
 	 			// cout << num << ' ' << s[i] << '\n';
 	 			if(s[i] < a[j] && i > 0){
 	 				num = (s[i - 1] - '0') * 10 + num;
 	 				i--;
 	 			}
 	 			// cout << num << '\n';
 	 			b += (num - (a[j] - '0')) + '0';
 	 		}
 	 		reverse(b.begin(), b.end());
 	 		string ans = "";
 	 		for (int i=a.size()-1; i>=0; i--){
 	 			int num = (a[i] - '0') + (b[i] - '0');
 				string tmp = to_string(num);
 				reverse(tmp.begin(), tmp.end());
 				ans += tmp;
 	 		}
 	 		reverse(ans.begin(), ans.end());
 	 		if(ans == s)cout << stoi("101") << '\n';
 	 		else cout << "-1\n";
 	 		cout << b << '\n' << ans << '\n';
 	 	}	
    return 0;
}