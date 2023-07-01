#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		if(n %2 == 0){
 			cout << (n-1)/2 << ' ' << (n-1)/2 + 1 << ' ' << 1 << '\n';
 		}
 		else {
 			int c = 1;
 			int a = (n-1)/2;
 			int b = a;
 			while(__gcd(a,b) != 1){
 				a--;
 				b++;
 			}
 			cout << a << ' '<< b << ' '<< c << '\n';
 		}
 	}	
    return 0;
}