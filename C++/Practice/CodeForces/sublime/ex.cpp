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
	fast_io();
    file_io();
 	int cs=1;
 	w(t){
 		int n,m;
 		cin >>n>>m;
 		double a,b;
 		cin >>a>>b;
 		double ara[n], sum=0;
 		for (int i=0; i<n; i++){
 			cin >>ara[i];
 			sum+=ara[i];
 		}
 		vector<pair<double,double>> vp(m);
 		for (int i=0; i<m; i++){
 			cin >>vp[i].first >> vp[i].second;
 		}	
 		vector<double> fg(m), gf(m);	
 		for (int i=0; i<m; i++){
 			gf[i]=vp[i].first*a*(sum)+ vp[i].first*b + n*vp[i].second -sum;
 		}
 		for (int i=0; i<m; i++){
 			fg[i]=vp[i].first*a*(sum)+ n*b + n*1.0*a*vp[i].second -sum;
 		}
 		for (int i=0; i<m; i++){
 			cout <<abs(gf[i]) + abs(fg[i])<<en;
 		}
 	}	
    return 0;
}