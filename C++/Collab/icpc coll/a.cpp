#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)

int main()
{
	fast_io();
	int a,b,c;
	cin >> a >>b >>c;
	int cnt=0;
 	for (int i=-100; i<101; i++){
 		for (int j=-100; j<101; j++){
 			for (int k=-100; k<101; k++){
 				for (int l=-100; l<101; l++){
 					if (abs(i)+abs(j)==a && abs(k)+abs(l)==b && abs(i-k)+abs(j-l)==c){
 						printf("%d %d %d %d\n",i,j,k,l);
 						cnt++;
 					}
 				}
 			}
 		}
 	}	
 	cout << cnt <<en;
    return 0;
}