#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		deque<int>a,ans,tmp, tmp2;
 		for (int i=0; i<n; i++){
 			int x;
 			cin >> x;
 			a.push_back(x);
 		}
 		tmp = a;
 		bool an = 1;
 		for (int i=0; i<n; i++){
 			int ba = a.back();
 			int fr = a.front();
 			if(ba == fr){
 				ans.push_back(ba);
 			}
 			else if(ba > fr){
 				ans.push_back(ba);
 				a.pop_back();
 			}
 			else {
 				ans.push_front(fr);
 				a.pop_front();
 			}
 		}
 		a = ans;
 		for (int i=0; i<n; i++){
 			int ba = a.back();
 			int fr = a.front();
 			if(ba == fr){
 				if(ba == tmp.back()){
 					tmp2.push_back(ba);
 					break;
 				}
 				else if(ba == tmp.front()){
 					tmp2.push_front(ba);
 					break;
 				}
 				else {
 					an = 0;
 					break;
 				}
 			}
 			else if(ba < fr){
 				tmp2.push_back(ba);
 				a.pop_back();
 			}
 			else {
 				tmp2.push_front(fr);
 				a.pop_front();
 			}
 		}
 		for (int i =0; i<ans.size(); i++){
 			if(tmp2[i] != tmp[i]){
 				an = 0;
 				break;
 			}
 		}
 		if(an){
 			for (int i=0; i<n; i++)cout << ans[i] << ' ' ;
 			cout << '\n';
 		}
 		else cout << "-1\n";
 	}	
    return 0;
}