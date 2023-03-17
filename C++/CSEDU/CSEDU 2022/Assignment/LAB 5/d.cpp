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
	int n,m;
	scanf("%d %d", &n, &m);
	int mat[105][105];
	for (int i=0; i<105; i++)
		for (int j=0; j<105; j++)mat[i][j]=0;
			int q;
		scanf("%d", &q);
		while(q--){
			char s[10];
			scanf("%s", s);
			if (s[0]=='A'){
				int x, y;
				scanf("%d %d", &x,&y);
				int tmp[x][y];
				for (int i=0; i<x; i++){
					for (int j=0; j<y; j++)scanf("%d", &tmp[i][j]);
				}
			if (n!=x || m!=y)
				printf("Invalid Operation!\n");
			else {
				for (int i=0; i<n; i++){
					for (int j=0; j<m; j++){
						mat[i][j] += tmp[i][j];
						printf("%d ",mat[i][j]);
					}
					printf("\n");
				}
			}
			printf("\n");
		}
		else if (s[0]=='S'){
			int x, y;
			scanf("%d %d", &x,&y);
			int tmp[x][y];
			for (int i=0; i<x; i++){
				for (int j=0; j<y; j++)scanf("%d", &tmp[i][j]);
			}
		if (n!=x || m!=y)
			printf("Invalid Operation!\n");
		else {
			for (int i=0; i<n; i++){
				for (int j=0; j<m; j++){
					mat[i][j] -= tmp[i][j];
					printf("%d ",mat[i][j]);
				}
				printf("\n");
			}
		}
		printf ("\n");
	}
	else if (s[0]=='M'){
		int x, y;
		scanf("%d %d", &x,&y);
		int tmp[x][y];
		for (int i=0; i<x; i++){
			for (int j=0; j<y; j++)scanf("%d", &tmp[i][j]);
		}
	if (x!=m || y!=n)printf("Invalid Operation!\n");
	else {
		int ans[n][y];
		for (int i=0; i<n; i++)
			for (int j=0; j<y; j++) ans[i][j]=0;
				for (int i=0; i<n; i++){
					for (int j=0; j<y; j++){
						for (int k=0; k<m; k++){
							ans[i][j]+=mat[i][k]*tmp[k][j];
						}
					}
				}
				m=y;
				for (int i=0; i<n; i++){
					for (int j=0; j<m; j++){
						mat[i][j]=ans[i][j];
						printf("%d ",ans[i][j]);
					}
					printf ("\n");
				}
				printf ("\n");
			}
		}
		else {
			char s2[10];
			scanf("%s", s2);
			int x;
			scanf("%d", &x);
			if (s2[0]=='C'){
				x%=4;
				if (x==3){
					int ans[m][n];
					int temp=m;
					m=n;n=m;
					for (int i=0; i<m; i++){
						for (int j=n-1, k=0; j>=0; k++,j--){
							ans [i][k] = mat[j][i];
						}
					}
					for (int i=0,k=n-1; i<n; i++,k--){
						for (int j=0, l=m-1; j<m; j++,l--){
							ans[i][k]=
						}
					}
				}
				else if (x==2){
					int ans[n][m];
					for (int i=n-1, k=0; i>=0; k++,i--){
						for (int j=m-1, l=0; j>=0; j--, l++){
							ans[k][l]= mat[i][j];
							printf ("%d ", ans[k][l]);
						}
						printf ("\n");
					}
				}
				else if (x==1){
					int ans[m][n];
					int temp=m;
					m=n;n=m;
					for (int i=0; i<m; i++){
						for (int j=n-1, k=0; j>=0; k++,j--){
							ans [i][k] = mat[j][i];
							printf ("%d ", ans[i][k]);
						}
						printf ("\n");
					}
				}
				else {
					for (int i=0; i<n; i++){
						for (int j=0; j<m; j++)printf ("%d ",mat[i][j]);
							printf ("\n");
					}
				}
				printf ("\n");
			}
			else {
				x%=4;
				if (x==3){
					int ans[m][n];
					int temp=m;
					m=n;n=m;
					for (int i=0; i<m; i++){
						for (int j=n-1, k=0; j>=0; k++,j--){
							ans [i][k] = mat[j][i];
							printf ("%d ", ans[i][k]);
						}
						printf ("\n");
					}
				}
				else if (x==2){
					int ans[n][m];
					for (int i=n-1, k=0; i>=0; k++,i--){
						for (int j=m-1, l=0; j>=0; j--, l++){
							ans[k][l]= mat[i][j];
							printf ("%d ", ans[k][l]);
						}
						printf ("\n");
					}
				}
				else if(x==1){
					int ans[m][n];
					int temp=m;
					m=n;n=m;
					for (int i=m-1,k=0; i>=0; k++,i--){
						for (int j=0;  j<n; j++){
							ans [k][j] = mat[j][i];
							printf ("%d ", ans[k][j]);
						}
						printf ("\n");
					}
				}
				else {
					for (int i=0; i<n; i++){
						for (int j=0; j<m; j++)printf ("%d ",mat[i][j]);
							printf ("\n");
					}
				}
				printf ("\n");
			}
		}
	}
	return 0;
}