#include <bits/stdc++.h>   
using namespace std;
 
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int N = 30;
vector<string> v(N);

bool valid(int ro, int col, int n){
	if(ro < 0 || ro >= n || col < 0 || col >= n)return 0;
	return 1;
}

void dfs(int ro , int col, int n){
	v[ro][col] = '0';
	for (int k = ro-1; k<= ro+1; k++){
		for (int l= col-1; l<= col+1; l++){
			if(k == ro && l == col)continue;
			if(valid(k, l, n) && v[k][l] == '1')dfs(k,l,n);
		}
	}
}


int main()
{
	// fast_io();
	int tc = 1;
 	while(1){
 		int n;
 		cin >> n;
 		if(feof(stdin))break;
 		v.clear();
 		for (int i=0; i<n; i++){
 			cin >> v[i];
 		}
 		int cnt = 0;
 		for (int i=0; i<n; i++){
 			for (int j=0; j<v[i].size(); j++){
 				if(v[i][j] == '0')continue;
 				cnt++;
 				for (int k = i-1; k<= i+1; k++){
 					for (int l= j-1; l<= j+1; l++){
 						if(k == i && l == j)continue;
 						if(valid(k, l, n) && v[k][l] == '1')dfs(k,l,n);
 					}
 				}
 			}
 		}
 		cout << "Image number " << tc++ <<  " contains " << cnt <<  " war eagles.\n";
 	}	
    return 0;
}