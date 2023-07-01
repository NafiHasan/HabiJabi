#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	w(t){
 		string s;
 		cin >> s;
 		map<char,int>m;
 		for (int i=0; i<s.size(); i++){
 			m[s[i]]++;
 		}
 		string ans;
 		for (int i=0; i<s.size(); i++){
 			if(m[s[i]]==1){
 				m[s[i]]=-1;
 				// ans+=s[i];
 			}
 		}
 		for (int i=0; i<s.size(); i++){
 			if(m[s[i]]==-1)ans+=s[i];
 			else if(i==s.size()-1 && m[s[i]]){
 				ans+=s[i];
 				break;
 			}
 			else if(m[s[i]]){
 				if(i<s.size()-1 && m[s[i]] > 0 && s[i]>=s[i+1]){
 					ans+=s[i];
 					m[s[i]]=0;
 				}
 				else if(i<s.size()-1 && m[s[i]] == 1 && s[i]<s[i+1]){
 					ans+=s[i];
 					m[s[i]]=0;
 				}
 				else if (i<s.size()-1 && m[s[i]]>1 && s[i] < s[i+1]){
 					m[s[i]]--;
 				}
 			}
 		}
 		// for (int i=0; i<s.size(); i++)if (s[i]!='A')cout << s[i];
 		cout << ans << en;
 	}	
    return 0;
}