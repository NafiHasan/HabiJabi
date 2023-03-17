#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool ly(int y){
	if(y % 4 == 0){
		if(y % 100 == 0 && y % 400 == 0)return 1;
		else if(y % 100 != 0)return 1;
	}
	return 0;
}

bool check(int d0, int d1, int m0, int m1, int y0, int y1){
	if(d0 + 1 == d1 && m0 == m1 && y0 == y1)return 1;
	if(y0 + 1 == y1){
		if(m0 == 12 && m1 == 1 && d0 == 31 && d1 == 1)return 1;
	}
	else if(y0 != y1)return 0;
	if((m0 <= 7 && m0 % 2== 1) || (m0 > 7 && m0 % 2 ==0)){
		if(d0 == 31 && d1 == 1)return 1;
	}
	if(ly(y0)){
		if(m0 == 2 && m1 == 3 && d0 == 29 && d1 == 1)return 1;
	}
	if(ly(y0) != 1){
		if(m0 == 2 && m1 == 3 && d0 == 28 && d1 == 1)return 1;
	}
	if(m0 == 9 || m0 == 11 || m0 == 4 || m0 == 6){
		if(d0 == 30 && d1 == 1)return 1;
	}
	return 0;
}

int main()
{
	fast_io();
	while(1){
		int n;
		cin >> n;
		if(n == 0)return 0 ;
		int d, m, y, c;
		int cost = 0, day = 0;
		for (int i=0; i<n; i++){
			int d1, m1, y1, c1;
			cin >> d1 >> m1 >> y1 >> c1;
			if(i == 0){
				d = d1, m = m1, c = c1, y = y1;
			}
			else {
				if(check(d, d1, m, m1, y, y1)){
					cost += c1 - c;
					day++;
				}
			}
			d = d1, m = m1, c = c1, y = y1;
		}
		cout << day << ' ' << cost << '\n';
	}	
    return 0;
}