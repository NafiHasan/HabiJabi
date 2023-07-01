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
 		string s;
 		cin >> s;
 		int on = 0;
 		for (int i=0; i<n; i++)if(s[i] == '1')on++;
 		vector<int>ans;
 		for (int i=n-1; i>=(n-on); i--){
 			if(s[i] == '0')ans.push_back(i+1);
 		}
 		for (int i=(n-on)-1; i>=0; i--){
 			if(s[i] == '1')ans.push_back(i+1);
 		}
 		sort(ans.begin(), ans.end());
 		if(ans.empty()) cout << "0" ;
 		if(!ans.empty()){
 			cout << "1\n";
 			cout << ans.size() << ' ';
 			for (int i=0; i<ans.size(); i++)cout << ans[i] << ' ';
 		}
 		cout << '\n';
 	}	
    return 0;
}