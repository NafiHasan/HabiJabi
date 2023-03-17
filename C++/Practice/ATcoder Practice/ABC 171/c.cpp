#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	w(t){
 		long long n;
 	cin >> n;
 	long long tmp=n;
 	string s;
 	vector<long long> v;
 	while(n>0){
 		long long mod= n%26LL;
 		if (mod==0LL) s+='z';
 		else s+=96+mod;
 		n/=26LL;
 		//if (n==1)break;
 	}	
 	reverse(s.begin(), s.end());
 	cout <<tmp << " " << s <<en;
 	}
    return 0;
}