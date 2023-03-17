#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, x, y;
 		cin >> n >> x >> y;
 		int last = max(1,min(n,(x + y) - 1));
 		int first = min(n,max(1,(x + y + 1) - n));
 		cout << first << ' ' << last << '\n'; 
 	}	
    return 0;
}