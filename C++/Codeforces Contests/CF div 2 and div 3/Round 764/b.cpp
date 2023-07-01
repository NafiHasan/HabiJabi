#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		long long a , b , c;
 		cin >> a >> b >> c;
 		if(b - a == c - b){
 			cout << "YES\n";
 			continue;
 		}
 		// changing mid one
 		long long dif = (c - a) /  2;
 		if((c- a) % 2 ==0){
 			dif += a;
 			if(dif != 0 && dif % b == 0){
 				cout << "YES\n";
 				continue;
 			}
 		}
 		// last one
 		dif = b - a;
 		dif += b;
 		if(dif > 0 && dif % c == 0){
 			cout << "YES\n";
 			continue;
 		}
 		// first one
 		dif = c - b;
 		dif *= 2;
 		dif = c - dif;
 		if(dif > 0 && dif % a == 0){
 			cout << "YES\n";
 			continue;
 		}
 		cout << "NO\n";
 	}	
    return 0;
}