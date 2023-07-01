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
 		int n;
 		cin >> n;
 		string s;
 		cin >> s;
 		int cnt1=0,cnt0=0;
		for (int i=1; i<n-1; i++){
			if(s[i]=='1')cnt1++;
			else cnt0++;
		}
		if(cnt1%2 || cnt0%2 || s[0]=='0' || s[n-1]=='0')cout << "NO\n";
		else {
			cout << "YES\n";
			vector<char>ans1(n),ans2(n);
			int cnt0=0,cnt1=0;
			for(int i=0; i<n; i++){
				if(s[i]=='1'){
					if((cnt1%2 && i!=n-1) || cnt1==0){
						ans1[i]='(';
						ans2[i]='(';
					}
					else {
						ans1[i]=')';
						ans2[i]=')';
					}
					cnt1++;
				}
				else {
					if(cnt0%2){
						ans1[i]=')';
						ans2[i]='(';
					}
					else {
						ans1[i]='(';
						ans2[i]=')';
					}
					cnt0++;
				}
			}
			for (int i=0; i<n; i++)cout << ans1[i];
			cout << en;
			for (int i=0; i<n; i++)cout << ans2[i];
			cout << en;
		}
 	}	
    return 0;
}