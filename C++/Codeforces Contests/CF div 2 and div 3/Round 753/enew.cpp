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
 		int mx = 1, mn = 1, ad = 0, ansc = 1;
 		for (int i=1; i<col.size(); i++){
 			col[i] += ad;
 			if(col[i] < 1 && (c-mx) >= (1-col[i])){
 				ad += (1-col[i]);
 				mx+= (1 - col[i]);
 				mn += (1 - col[i]);
 				col[i] += ad;
 			}
 			else if(col[i] > c && (mn - 1) >= (col[i] - c)){
 				ad -= col[i] - c;
 				mx -= col[i] - c;
 				mn -= col[i] - c;
 				col[i] += ad;
 			}
 			mx = max(mx, col[i]);
 			mn = min(mn, col[i]);
 		}
 		// cout << "ans = " <<  1 + ad << '\n';
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
 		int mx2 = 1, mn2 = 1, ad2 = 0;
 		for (int i=1; i<row.size(); i++){
 			row[i] += ad2;
 			if(row[i] < 1 && (r-mx2) >= (1-row[i])){
 				ad2 += (1-row[i]);
 				mx2+= (1 - row[i]);
 				mn2 += (1 - row[i]);
 				row[i] += ad2;
 			}
 			else if(row[i] > r && (mn2 - 1) >= (row[i] - r)){
 				ad2 -= row[i] - r;
 				mx2 -= row[i] - r;
 				mn2 -= row[i] - r;
 				row[i] += ad2;
 			}
 			mx2 = max(mx2, row[i]);
 			mn2 = min(mn2, row[i]);
 		}
 		cout << ad2 + 1 << ' ' << ad + 1 << '\n';
 	}	
    return 0;
}