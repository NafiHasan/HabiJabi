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
		bool ok=0;
		for (int i=0; i<s.size(); i++)if(s[i]!='a')ok=1;
		if(ok==0){
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			string n;
			bool pal=1;
			for (int i=0,j=s.size()-1; i<s.size(); i++,j--){
				if(s[i]!=s[j])pal=0;
			}
			if(!pal){
				int done=0;
				for (int i=0,j=s.size()-1; i<s.size() ; i++,j--){
					if(s[j]!='a' && done==0){
						n+='a';
						n+=s[i];
						done=1;
					}
					else {
						n+=s[i];
					}
				}
				cout << n <<en;
			}
			else {
				s+='a';
				cout << s <<en;
			}
		}
	}
    return 0;
}