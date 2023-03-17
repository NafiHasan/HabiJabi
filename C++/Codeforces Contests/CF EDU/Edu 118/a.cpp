#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int x1,p1, x2, p2;
 		cin >> x1 >> p1 >> x2 >> p2;
 		int mn = min(p1, p2);
 		p1 -= mn, p2-= mn;
 		if(p2 == p1){
 			if(x1 == x2) cout << "=\n";
 			else if(x1 > x2) cout << ">\n";
 			else cout << "<\n";
 		}
 		else if(p1 > p2){
 			int mod = 0;
 			string s = to_string(x2);
 			if((int)s.size() <= p1){
 				cout << ">\n";
 			}
 			else {
 				int ss = (int)s.size() - p1;
 				mod = s[ss] - '0';
 				s = s.substr(0,ss);
 				// cout << s << '\n';
 				int nw = stoi(s);
 				if(x1 == nw && mod == 0) cout << "=\n";
 				// else if(x1 == x2 && mod != 0)cout << "<\n";
 				else if(x1 < nw) cout << "<\n";
 				else cout << ">\n";
 			}
 			// while(p1--){
 			// 	mod = x2 % 10;
 			// 	x2/=10;
 			// }
 			// if(x1 == x2 && mod == 0) cout << "=\n";
 			// // else if(x1 == x2 && mod != 0)cout << "<\n";
 			// else if(x1 > x2) cout << ">\n";
 			// else cout << "<\n";
 		}
 		else{
 			int mod = 0;
 			string s = to_string(x1);
 			if((int)s.size() <= p2){
 				cout << "<\n";
 			}
 			else {
 				int ss = (int)s.size() - p2;
 				mod = s[ss] -'0';
 				s = s.substr(0,ss);
 				int nw = stoi(s);
 				if(x2 == nw && mod == 0) cout << "=\n";
 				// else if(x1 == x2 && mod != 0)cout << "<\n";
 				else if(x2 > nw) cout << "<\n";
 				else cout << ">\n";
 			}
 		}
 	}	
    return 0;
}