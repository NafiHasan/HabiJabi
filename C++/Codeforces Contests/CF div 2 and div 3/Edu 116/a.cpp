#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		string s;
 		cin >> s;
 		int n = s.size();
 		int ab = 0, ba = 0;
 		for (int i=0; i<n; i++){
 			if(s[i] == 'a' && i < n-1 && s[i+1] == 'b')ab++;
 			else if(s[i] == 'b' && i < n-1 && s[i+1] == 'a')ba++;
 		}
 		if(ab != ba){
 			for (int i=0; i<n; i++){
 				string tmp = s;
 				if(tmp[i] == 'a')tmp[i] = 'b';
 				else tmp[i] = 'a';
 				int a = 0, b = 0;
 				for (int i=0; i<n-1; i++){
 					if(tmp[i] == 'a' && tmp[i+1] == 'b')a++;
 					else if(tmp[i] == 'b' && tmp[i+1] == 'a')b++;
 				}
 				if(a == b){
 					s[i] = tmp[i];
 					break;
 				}
 			}
 		}
 		cout << s << '\n';
 	}
    return 0;
}