#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	int cs = 1;
 	while(tc--){
 		int x1l, x2l, y1l, y2l, x1r, x2r, y1r, y2r;
 		cin >> x1l >> y1l >> x1r >> y1r >> x2l >> y2l >> x2r >> y2r;
 		int xl, yl, xr , yr;
 		xl = max(x1l, x2l);
 		yl = max(y1l, y2l);
 		xr = min(x2r, x1r);
 		yr = min(y2r, y1r);
 		if(cs > 1) cout << "\n";
 		if(xl < xr && yl < yr)cout << xl << ' ' << yl << ' ' << xr << ' ' << yr << '\n';
 		else cout << "No Overlap\n";
 		cs++;
 	}	
    return 0;
}