#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	double a, b , c ,d ;
 	cin >> a >> b >> c >> d;
 	double x = a/b;
 	double y = (1 - x) * (1 - (c/d));
 	y = 1 - y;
 	cout << fixed << setprecision(10) << x/y << '\n';
    return 0;
}