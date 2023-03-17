#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	int n, k;
 	cin >> n >>k;
 	string s;
 	for (int i=0; i<k; i++){
 		for (int j=i; j<k; j++){
 			s+=j+'a';
 			s+=i+'a';
 			
 		}
 	}
 	while((int)s.size() < n)s+=s;
 	while((int)s.size() > n){
 		s.pop_back();
 	}
 	cout << s << en;
    return 0;
}