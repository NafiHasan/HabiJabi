#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
    int cs=1;
 	w(t){
 		int n,m,k;
 		cin >>m>>n>>k;
 		vector<string>v(m);
 		map<string,int>mp,mp2;
 		for (int i=0; i<m; i++){
 			cin >>v[i];
  			mp[v[i]]++;
 		}
 		vector<string>ans,ans2;
 		for (int i=0; i<m; i++){
 			mp2[v[i]]++;
 			int hav=(mp[v[i]]/k);
 			if (hav>1)hav++;
 			if (mp2[v[i]] > hav*k){
 				ans2.push_back(v[i]);
 			}
 			else if (hav == 0 )ans2.push_back(v[i]);
 			else if (mp2[v[i]]<(hav*k) && mp2[v[i]]==1){
 				if (hav==1)ans.push_back(v[i]+'2');
 				else if (hav>1)ans.push_back(v[i]+'3');
 			}
 		}
 		cout << "Case "<<cs++<<": ";
 		for (int i=0; i<ans.size(); i++){
 			cout << ans[i]<< " ";
 		}
 		for (int i=0; i<ans2.size(); i++)cout <<ans2[i]<<" ";
 		for (int i=ans.size()+ans2.size(); i<n; i++)cout <<"-1 ";
 		cout <<en;
 	}	
    return 0;
}