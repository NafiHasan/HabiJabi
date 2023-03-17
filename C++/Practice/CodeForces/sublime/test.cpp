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

double g(double x, double c, double d){
	double ans= c*x+d;
	return ans;
}

double f(double x, double a, double b){
	double ans= a*x+b;
	return ans;
}
// double fg(double x,){
// 	double ans=g(x,)
// }

int main()
{
	fast_io();
    file_io();
 	int n,m;
 	cin >> n >>m;
 	double a, b;
 	cin >>a>>b;
 	double ara[n];
 	for (int i=0; i<n; i++)cin >>ara[i];
 	vector<pair<int,int>> vp(m);
 	for (int i=0; i<m; i++){
 		cin >> vp[i].first << vp[i].second;
 	}
 	vector<double> fg(m), gf(m);
 	for (int i=0; i<m; i++){
 		fg[i]=
 	}
 	while(m--){
 		double c, d;
 		cin >> c >> d;
 		double ans=0;
 		for (int i=0; i<n; i++){
 			double x=ara[i];
 			ans+=abs(f(g(x,c,d),a,b)-x);
 			ans+=abs(g(f(x,a,b),c,d)-x);
 		}
 		cout << en << ans << en;
 	}
    return 0;
}