#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int r, c;
 		cin >> r >> c;
 		string s;
 		cin >> s;
 		vector<int>col, row;
 		int st = 1;
 		col.push_back(1);
 		for (int i=0; i<s.size(); i++){
 			if(s[i] == 'L'){
 				st--;
 				col.push_back(st);
 			}
 			else if(s[i] == 'R'){
 				st++;
 				col.push_back(st);
 			}
 		}
 		int mx = 1, mn = c, ad = 0, ansc = 1;
 		for (int i=1; i<col.size(); i++){
 			col[i]+=ad;
 			mx = max(mx, col[i]);
 			mn = min(mn, col[i]);
 			if(col[i] <= 0){
 				if((c - mx) >= (1 - col[i])){
 					ad += 1-col[i];
 					mx += 1-col[i];
 					// if(ad <= 0 )cout << i;
 					ansc = min(c, mx);
 				}
 				else break;
 			}
 			else if(col[i] > c){
 				if((mn - 1) >= (col[i] - c)){
 					// cout << ad << '\n';
 					ad -= col[i] - c;
 					mn -= col[i] - c;
 					ansc = max(1, mn);
 					// if(ad <= 0 )cout << col[i] << ' ' << ad << ' ' << mx;
 				}
 				else break;
 			}
 		
 			if(mx > c || mx < 1 || mn > c || mn < 1)break;
 		}

 		// row
 		int ver = 1;
 		row.push_back(1);
 		for (int i=0; i<s.size(); i++){
 			if(s[i] == 'U'){
				ver--;
 				row.push_back(ver);
 			}
 			else if(s[i] == 'D'){
 				ver++;
 				row.push_back(ver);
 			}
 		}
 		int mx2 = 1, mn2 = r, ad2 = 0, ansr = 1;
 		for (int i=1; i<row.size(); i++){
 			row[i]+=ad2;
 			mx2 = max(mx2, row[i]);
 			mn2 = min(mn2, row[i]);
 			if(row[i] <= 0){
 				if((r - mx2) >= (1 - row[i])){
 					ad2 += 1-row[i];
 					mx2 += 1-row[i];
 					ansr = min(mx2, r);
 				}
 				else break;
 			}
 			else if(row[i] > r){
 				if((mn2 - 1) >= (row[i] - r)){
 					ad2 -= row[i] - r;
 					mn2 -= row[i] - r;
 					ansr = max(mn2, 1);
 				}
 				else break;
 			}
 			// cout << mx2 << ' ' << mn2 << '\n';
 			// if(mx2 > r || mx2 < 1 || mn2 > r || mn2 < 1)break;
 		}
 		cout << ad + 1 << ' ' << ad2 + 1 << '\n';
 	}	
    return 0;
}