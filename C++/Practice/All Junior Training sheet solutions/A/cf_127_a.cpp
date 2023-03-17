#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	double n, k;
 	cin >> n >> k;
 	double ans = 0;
 	double prx , pry;
 	for (int i=0; i<n; i++){
 		double x, y;
 		cin >> x >> y;
 		if(i){
 			ans += sqrt((prx - x) * (prx - x) + (pry - y) * (pry - y));
 		}
 		prx = x, pry = y;
 	}	
 	ans *= k;
 	ans /= 50.0;
 	cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}