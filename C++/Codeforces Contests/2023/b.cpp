#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		if(n == 3)cout << "NO\n";
 		else {
 			cout << "YES\n";
 			if(n % 2 == 0){
 				for (int i=0; i<n; i++){
 				if(i % 2)cout << "-1 ";
 				else cout << "1 ";
 			}
 				cout << "\n";
 			}
 			else {
 				int tmp = (n - 2)/2;
 				for (int i=0; i<n; i++){
 					if(i % 2 == 0)cout << tmp << ' ';
 					else cout << "-" << tmp + 1 << ' ';
 				}
 				cout << "\n";
 			}
 		}
 	}	
    return 0;
}