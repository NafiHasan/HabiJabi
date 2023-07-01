#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int sum(int n){
	int sum=0;
 	while(n){
 		sum+=n%10;
 		n/=10;
 	}
 	return sum;
}

int main()
{
	fast_io();
 	int n;
 	cin >> n;
 	while(n/10){
 		n=sum(n);
 	}
 	cout << n <<en;
    return 0;
}