#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

// int diajkstra()

int main()
{
	fast_io();
	int n;
	cin >> n;
	priority_queue<int> q;
	for(int i=0; i<n; i++){
		int v;
		cin>> v;
		q.push(v);
	} 		
	while(q.size()){
		int top=q.top();
		q.pop();
		cout << top << en;
	}
    return 0;
}