#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
 	int cs=1;
 	w(t){
 		int n;
 		cin >> n;
 		cout << "Case #" << cs++ << ": ";
 		if (n%2)cout << "1\n";
 		else if (n==6)cout << "-1\n";
 		else if (n%3==0 || (n/2)%2==0)cout << "2\n";
 		else if ((n/2)%2){
 			int a=n/3;
 			if (__gcd(a-1,a+2)==1 && 3*a+1==n)cout <<"3\n";
 			else if (__gcd(a-1,a+2)==1 && 3*a+2==n)cout << "3\n";
 			else cout << "4\n";
 		}
 		else cout << "4\n";
 	}	
    return 0;
}