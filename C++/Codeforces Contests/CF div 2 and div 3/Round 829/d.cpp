#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int n, k;
 	cin >> n >> k;
 	vector<int> a(n), freq(k + 5, 0);
 	for (int i=0; i<n; i++){
 		cin >> a[i];
 		freq[a[i]]++;
 	}	
 	bool ok = 1;
 	for (int i=1; i<k; i++){
 		freq[i + 1] += freq[i]/(i + 1);
 		freq[i] %= (i + 1);
 		if(freq[i] != 0){
 			ok = 0;
 			break;
 		}
 	}
 	if(ok)cout << "YES\n";
 	else cout << "NO\n";
    return 0;
}