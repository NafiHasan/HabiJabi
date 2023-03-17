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
 		int w1, h1, w2,h2;
 		cin >>w1 >> h1 >> w2 >> h2;
 		if (w1<h1)swap(w1,h1);
 		if (w2<h2)swap(w2,h2);
 		double area=(w1*h1)+(w2*h2);
 		double a2=.5*(abs(w1-w2));
 		if (w1<w2){
 			a2*=h1;
 		}
 		else a2*=h2;
 		double a3=.5*(abs(h1-h2));
 		if (h1<h2)a3*=w1;
 		else a3*=w2;
 		a2=min(a2,a3);
 		double a4=.5*(abs(h1-w2));
 		if (h1<w2)a4*=w1;
 		else a4*=h2;
 		a2=min(a2,a4);
 		double a5=.5*(abs(w1-h2));
 		if (w1<h2)a5*=h1;
 		else a5*=w2;
 		a2=min(a2,a5);
 		cout << fixed << setprecision(12) <<"Case "<<cs++<<": "<< area+a2<<en; 
 	}	
    return 0;
}