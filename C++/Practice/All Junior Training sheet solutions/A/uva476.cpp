#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	vector<pair<pair<double, double>, pair<double, double>>> vp;
 	char c ;
 	while(1){
 		cin >> c;
 		if(c == '*')break;
 		double lx, ly, rx, ry;
 		cin >> lx >> ly >> rx >> ry;
 		vp.push_back({{lx,ly}, {rx,ry}});
 	}
 	int cs = 1;
 	while(1){
 		double x, y ;
 		cin >> x >> y;
 		if(x == 9999.9 && y == 9999.9)break;
 		bool ans = 0;
 		vector<int>ind;
 		for (int i=0; i<vp.size(); i++){
 			if(vp[i].first.first < x && vp[i].second.first > x && vp[i].first.second > y && vp[i].second.second < y){
 				ans = 1;
 				ind.push_back(i+1);
 			}
 		}
 		if(ans){
 			for (int i=0; i<ind.size(); i++){
 				cout << "Point " << cs <<  " is contained in figure " << ind[i]<< '\n';
 			}
 		}
 		else {
 			cout << "Point " << cs << " is not contained in any figure\n";
 		}
 		cs++;
 	}
    return 0;
}