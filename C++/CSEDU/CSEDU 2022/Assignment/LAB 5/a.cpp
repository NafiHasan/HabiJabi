#include <stdio.h>  


int main()
{
 	int m,n;
 	scanf("%d %d", &m, &n);
	int mat[m][n] , trans[n][m];
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &mat[i][j]);
			trans[j][i]=mat[i][j];
		}
	}	
	for (int i=0; i<n; i++){
		if(i)printf("\n");
		for (int j=0; j<m; j++){
			if (j)printf(" ");
			printf("%d",trans[i][j]);
		}
	}	
	printf("\n");
    return 0;
}