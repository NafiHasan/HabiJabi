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
 		int ind = 0, x, mn = 1e9 + 4;
 		for (int i=0; i<n; i++){
 			cin >> x;
 			if(x < mn){
 				mn = x;
 				ind = i;
 			}
 		}
 		if(ind)cout << "Alice\n";
 		else cout << "Bob\n"; 
 	}	
    return 0;
}