#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long n;
 		cin >> n;
 		long long a = -1, b = -1;
 		for (long long i = 2LL; i * i <= n; i++){
 			if(n % i == 0 && n/i != i){
 				a = n/i;
 				b = i;
 			}
 		}
 		if(a != -1)cout << "1 " << a << ' ' << b << '\n';
 		else cout << "-1\n";
 	}	
    return 0;
}