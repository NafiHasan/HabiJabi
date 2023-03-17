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
int mem[10000];

int f(int start, vector<int> &A){
	if (mem[start] !=-1) return mem[start];

	int ans=0;
	for(int i=start+1; i<A.size(); i++) {
		if (A[i] > A[start]) ans = max(ans, f(i,A));
	}
	mem[start]=ans+1;
	return mem[start];
}


int findlis(vector<int> A){
    int ans = 0;
  
    for(int i = 0;i<A.size();i++) {
      ans = max(ans, f(i, A));
	}
	return ans;
}
int main()
{
    fast_io();
    file_io();
 	int n;
 	cin >> n;
 	memset(mem,-1,sizeof(mem));
 	vector<int> v(n);
 	for(int i=0; i<n; i++) {
 		cin >> v[i];
 	}
 	cout << findlis(v) << en;
    return 0;
}