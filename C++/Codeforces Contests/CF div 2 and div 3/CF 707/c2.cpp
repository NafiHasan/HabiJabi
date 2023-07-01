#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
void file_io(){
	#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	#endif
}

int main()
{
	fast_io();
    file_io();
 	int n;
 	cin >> n;
 	int a[n];
 	for (int i=0; i<n; i++) cin >> a[i];
 	vector<int> sumx(5000100,-1), sumy(5000100, -1);
 	for (int i=0; i<n-1; i++){
 		for (int j=i+1; j<n; j++){
 			int tmp=a[i]+a[j];
 			if(sumx[tmp]==-1){
 				sumx[tmp]=i;
 				sumy[tmp]=j;
 			}
 			else if (sumx[tmp]!=i && sumx[tmp]!=j && sumy[tmp]!=i && sumy[tmp]!=j){
 				cout << "YES\n" << i+1 << " " << j+1 << " "<< sumx[tmp]+1 << " " << sumy[tmp]+1 << en;
 				return 0;
 			}
 		}
 	}	
 	cout << "NO\n";
    return 0;
}