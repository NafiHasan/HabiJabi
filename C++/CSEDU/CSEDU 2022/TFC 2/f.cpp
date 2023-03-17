#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int n, k;
 	cin>> n >> k;
 	vector<pair<int,int>>st, pe;
 	map<int,int>mm;
 	for (int i=0; i<n; i++){
 		int c, t;
 		cin >> c >> t;
 		if(t == 1)st.push_back({c,i+1});
 		if(t == 2)pe.push_back({c,i+1});
 	}	
 	sort (st.rbegin(), st.rend());
 	sort(pe.begin(), pe.end());
 	double ans = 0;
 	
 	if((int)st.size() > (k-1)){
 		for (int i=0; i<min(k-1, (int)st.size()); i++){
 			ans += (double)st[i].first / 2.0;
 			mm[st[i].second]++;
 		}
 		if(!pe.empty() && st.back().first > pe[0].first){
 			ans += (double)pe[0].first/ 2.0;
 			mm[pe[0].second] = 2;
 			for (int i=1; i<pe.size(); i++){
 				ans += pe[i].first;
 				mm[pe[i].second] = 2;
 			}
 			for (int i=0; i<st.size(); i++){
 				if(mm[st[i].second] == 0)ans += st[i].first;
 			}
 		}
 		else {
 			ans += (double)st.back().first / 2.0;
 			for (int i=0; i<pe.size(); i++){
 				ans += pe[i].first;
 				mm[pe[i].second] = 2;
 			}
 			for (int i=0; i<st.size()-1; i++){
 				if(mm[st[i].second] == 0){
 					ans += st[i].first;
 					mm[st[i].second] = 2;
 				}
 			}
 		}
 		int cnt = 0;
 		cout << fixed << setprecision(1) << ans << '\n';
 		for (int i=0; i<k-1; i++){
 			cout << "1 " << st[i].second << '\n';
 		}
 		cout << (n - k + 1) << ' ';
 		for (int i=k-1; i<st.size(); i++)cout << st[i].second << ' ';
 		for (int i=0; i<pe.size(); i++)cout << pe[i].second << ' ' ;
 		cout << '\n';
 	}
 	else {
 		for (int i=0; i<st.size(); i++){
 			ans += (double)st[i].first / 2.0;
 			mm[st[i].second]++;
 		}
 		for (int i=0; i<pe.size(); i++){
 			ans += pe[i].first;
 		}
 		cout << fixed << setprecision(1) << ans << '\n';
 		int cnt  =0;
 			for (int i=0; i<st.size() && cnt < k-1; i++){
 				cout << "1 " << st[i].second << '\n'; 
 				mm[st[i].second] = 5;
 				cnt++;
 			}
 			for (int i=0; i<pe.size() && cnt < k-1; i++){
 				cout << "1 " << pe[i].second << '\n';
 				mm[pe[i].second] = 5;
 				cnt++;
 			}
 			cout << (n- cnt) << ' ';
 			for (int i=0; i< st.size(); i++){
 				if(mm[st[i].second] != 5 )cout << st[i].second << ' ';
 			}
 			for (int i=0; i<pe.size(); i++){
 				if(mm[pe[i].second] != 5)cout << pe[i].second << ' ';
 			}
 			cout << '\n';
 	}
    return 0;
}