#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

double eps = 1e-9;

int main()
{
	fast_io();
	double a, b, m, vx, vy, vz;
	cin>> a >> b >> m >> vx >> vy >> vz;
	double x = a/2.0, y = m , z = 0;
	int cnt = 0;
	while(y > 0.0){
		cnt ++;
		double tx, ty, tz;
		if(vx > 0)tx = abs(a - x) / abs(vx);
		else tx = abs(x - 0) / abs(vx);
		ty = abs(0.0 - y) / abs(vy);
		if(vz > 0)tz = abs(b - z) / abs(vz);
		else tz = abs(z - 0) / abs(vz);
		double tim = min(tx, min(ty, tz));
		x += vx * tim, y += vy * tim , z += vz * tim;
		if((vx > 0 && abs(x - a) < eps) || (vx < 0 && (abs)(x-0) < eps)) vx = vx * (-1);
		if((vz > 0 && abs(z - b) < eps) || (vz < 0 && (abs)(z - 0) < eps))vz = vz * (-1);
	} 
	cout  << fixed << setprecision(10) << x << ' ' << z << '\n';
    return 0;
}