#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
	int tc;
	cin >> tc;
	while(tc--){
		int a, b, c;
		cin >> a >> b >> c;
		int mx = max(a, max(b,c));
		int dif = 0;
		if(mx == a){
			if(mx == b || mx == c)dif++;
			cout << dif << ' ' << mx - b + 1 << ' ' << mx - c +1 << '\n';
		}
		else if(mx == b){
			if(mx == a || mx == c)dif++;
			cout << mx - a + 1 << ' ' << dif << ' ' << mx - c +1 << '\n';
		}
		else {
			if(mx == a || mx == b)dif++;
			cout << mx - a + 1 << ' ' << mx - b + 1 << ' ' << dif << '\n';
		}
		
	}
    return 0;
}