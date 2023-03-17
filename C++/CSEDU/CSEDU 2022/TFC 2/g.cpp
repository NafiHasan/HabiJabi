#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n, m , ti, p, q;
 		cin >> n >> m >> ti >> p >> q; 
 		vector<int>vir(ti), rohi(ti);
 		int pre = 1;
 		for (int i=0; i<ti; i++){
 			int tmp = pre + p;
 			if(tmp >= m){
 				tmp -= m;
 				tmp %= (n-m+1);
 				tmp += m;
 			}
 			vir[i] = tmp;
 			pre = tmp;
 		}
 		pre = 1;
 		for (int i=0; i<ti; i++){
 			int tmp = pre + q;
			if(tmp >= m){
				tmp -= m;
				tmp %= (n-m+1);
				tmp += m;
			}
			rohi[i] = tmp;
 			pre = tmp;
 		}
 		int cnt = 0;
 		for (int i=0; i<ti; i++){
 			// cout << vir[i] << ' ' << rohi[i] << '\n';
 			if(vir[i] == rohi[i])cnt++;
 		}
 		cout << cnt << '\n';
 	}	
    return 0;
}