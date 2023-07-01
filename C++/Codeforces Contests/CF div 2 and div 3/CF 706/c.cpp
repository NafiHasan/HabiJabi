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
    //file_io();
    fast_io();
 	w(t){
 		int n;
 		cin >> n;
 		long double ans=0.0;
 		priority_queue<double>a;
 		priority_queue<double>b;
 		for (int i=0; i<2*n; i++){
 			double x,y;
 			cin >>x>>y;
 			if (x==0) a.push(abs(y));
 			else b.push(abs(x));
 		}
 		// sort (a.begin(),a.end());
 		// sort (b.begin(),b.end());
 		//for (int i=0; i<n; i++)cout <<a[i] <<" "<<b[i]<<en;
 		while (a.size() || b.size()){
 			double x=a.top(); a.pop();
 			double y=b.top(); b.pop();
 			ans+=sqrt(x*x+y*y);
 			//cout <<sqrt(a[i]*a[i]+b[i]*b[i]) <<en;
 		}
 		cout <<fixed <<setprecision(12) <<ans<<en;
 	}
    return 0;
}