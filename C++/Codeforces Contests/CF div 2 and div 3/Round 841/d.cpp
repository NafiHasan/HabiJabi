#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 505, LG = 10;

int st[N][N][LG][LG];
int a[N][N], lg2[N];

int yo(int x1, int y1, int x2, int y2) {
  x2++;
  y2++;
  int a = lg2[x2 - x1], b = lg2[y2 - y1];
  return max(
         max(st[x1][y1][a][b], st[x2 - (1 << a)][y1][a][b]),
         max(st[x1][y2 - (1 << b)][a][b], st[x2 - (1 << a)][y2 - (1 << b)][a][b])
       );
}

void build(int n, int m) { // 0 indexed
  for (int i = 2; i < N; i++) lg2[i] = lg2[i >> 1] + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      st[i][j][0][0] = a[i][j];
    }
  }
  for (int a = 0; a < LG; a++) {
    for (int b = 0; b < LG; b++) {
      if (a + b == 0) continue;
      for (int i = 0; i + (1 << a) <= n; i++) {
        for (int j = 0; j + (1 << b) <= m; j++) {
          if (!a) {
            st[i][j][a][b] = max(st[i][j][a][b - 1], st[i][j + (1 << (b - 1))][a][b - 1]);
          } else {
            st[i][j][a][b] = max(st[i][j][a - 1][b], st[i + (1 << (a - 1))][j][a - 1][b]);
          }
        }
      }
    }
  }
}






int main() {
	FastIO;
 	int tc;
 	cin>> tc;
 	while(tc--){
 		int n, m;
 		cin>> n >> m;
 		int lg = log(max(n, m));
 		int a[n + 5][m + 5], st[lg + 5][n + 5][lg + 5][m + 5];

 		for (int i=0; i<n; i++){
 			for (int j=0; j<m; j++)cin >> a[i][j];
 		}

 		for(int ir=0;ir<n;ir++){
 		  for(int ic=0;ic<m;ic++)
 		    st[0][ir][0][ic] = a[ir][ic];
 		       
 		  for(int jc=1;jc<=log2(m);jc++)
 		    for(int ic=0;ic+ ( 1 << (jc -1))<m;ic++)
 		     st[0][ir][jc][ic] = min(st[0 ][ir ][jc-1 ][ic ],st[0 ][ir ][ jc-1 ][ ic+ (1 << (jc - 1)) ]);
 		} 


 		for(int jr=1;jr<=log(n);jr++)
 		  for(int ir=0;ir<n;ir++)
 		    for(int jc=0;jc<=log(m);jc++)
 		      for(int ic=0;ic<m;ic++)
 		        st[jr ][ir ][jc ][ic ] = min(st[jr-1 ][ir ][jc ][ic ],st[jr-1 ][ir+ (1 << (jr-1)) ][jc ][ic ]);

 		int lo = 1, hi = min(n, m), mid, ans = 1;
 		while(lo <= hi){
 			mid = (lo + hi)/2;
 			int pos = 1;
 			for (int i=0; i< n - mid + 1; i++){
 				for (int j=0; j< m - mid + 1; j++){
 					// cout << i << ' '<< j << '\n';
 					// if(i + mid - 1 >= n || j + mid - 1 >= m)continue;
 					int x1 = i, x2 = i + mid - 1, y1 = j, y2 = j + mid - 1;
					int lenx=x2-x1+1;
 					int kx=log(lenx);
					int leny=y2-y1+1;
					int ky=log(leny);
					int mn1 = min ( st[kx ][x1 ][ky ][y1 ] , st[kx ][x1 ][ky ][ y2+1-(1 << ky) ] ) ;
  					int mn2 = min ( st[kx ][x2+1- (1 << kx) ][ky ][y1 ], st[kx ][x2+1-(1 << kx) ][ky ][y2+1- (1 << ky) ]);
  					pos = max(pos, min(mn1, mn2));
  					// cout << i << ' '<< j << ' '<< mid << ' ' << pos << '\n';
 				}
 			}
 			if(pos < mid){
 				hi = mid - 1;
 			}
 			else {
 				ans = max(ans, mid);
 				lo = mid + 1;
 			}
 		}
 		cout << ans << '\n';
 	}
    return 0;
}