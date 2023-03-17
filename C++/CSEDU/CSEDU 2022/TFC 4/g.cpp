#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n, k;
 		cin >> n >> k;
 		if(n % 2){
 			cout << "impossible\n";
 			continue;
 		}
 		n/=2;
 		bool ans = 1;
 		string s = "";
 		int dec = 2, cl = 0;
 		if(k < n)ans =0;
 		while(k >= n){
 			if(n == 1 && k > 1){
 				ans = 0;
 				break;
 			}
 			if(n ==1 && k == 1){
 				s+="()";
 				break;
 			}
 			if((k - dec) >= (n-1)){
 				k -= dec;
 				dec++;
 				n--;
 				s += "()";
 			}
 			else if((k-1) >= (n-1)){
 				k--;
 				n--;
 				dec = 2;
 				s += "(";
 				cl++;
 			}
 			else {
 				ans = 0;
 				break;
 			}
 		}
 		if(n == 1 && k > 1){
 			ans = 0;
 		}
 		for (int i=0; i<cl; i++) s+=")";
 		if(ans)cout << s << '\n';
 		else cout << "impossible\n";
 	}	
    return 0;
}