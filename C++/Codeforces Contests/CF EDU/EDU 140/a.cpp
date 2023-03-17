#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	int tc;
 	cin >> tc;
 	while(tc--){
 		map<int,int> mp, mp2;
 		bool ok1 = 1, ok2 = 1;
 		for (int i=0; i<3; i++){
 			int x, y;
 			cin >> x >> y;
 			mp[x]++; mp2[y]++;
 			if(mp[x] >= 2)ok1 = 0;
 			if(mp2[y] >= 2)ok2 = 0;
 		}
 		if(!ok1 && !ok2)cout << "NO\n";
 		else cout << "YES\n";
 	}	
    return 0;
}