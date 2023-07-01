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
 		vector<int> a(n);
 		int o = 0, an = 1;
 		for (int i=0; i<n; i++){
 			cin >> a[i];
 			o |= a[i];
 			if(i)an &= a[i];
 			else an = a[i];
 		}
 		cout <<o - an << '\n';
 	}	
    return 0;
}