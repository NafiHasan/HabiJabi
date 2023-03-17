#include<stdio.h>

int mat[1005][1005] ,m,n;

void leftright(int a, int i, int j){
	if (i>m-1 || j>n-1){
		printf("\n");
		return;
	}
	if (a==1){
		if (j<n-1){
			printf("%d ",mat[i][j]);
			leftright(1,i,j+1);
		}
		else {
			printf("%d ",mat[i][j]);
			leftright(-1,i+1,j);
		}
	}
	else if(a==-1){
		if (j==0){
			printf("%d ",mat[i][j]);
			leftright(1,i+1,j);
		}
		else {
			printf("%d ",mat[i][j]);
			leftright(-1,i-1,j);
		}
	}
}
// void updown(char a, int i, int j){
// 	if (i==m && j==n){
// 		printf("\n");
// 		return ;
// 	}
// 	else if(a=='d'){
// 		if (i==m-1){
// 			printf("%d ",mat[i][j]);
// 			updown('u',i,j+1);
// 		}
// 		else {
// 			printf("%d ",mat[i][j]);
// 			updown('d',i+1,j);
// 		}
// 	}
// 	else if (a=='u'){
// 		if (i==0){
// 			printf("%d ",mat[i][j]);
// 			updown('d',i,j+1);
// 		}
// 		else {
// 			printf("%d ",mat[i][j]);
// 			updown('u',i-1,j);
// 		}
// 	}
// }
// void zigzag(char a, int i ,int j){
// 	if (i==m && j==n){
// 		printf("\n");
// 		return ;
// 	}
// 	else if(a=='d'){
// 		if (i==m-1){
// 			printf("%d ",mat[i][j]);
// 			zigzag('u',i,j+1);
// 		}
// 		else if (j==0){
// 			printf("%d ",mat[i][j]);
// 			zigzag('u',i-1,j+1);
// 		}
// 		else {
// 			printf("%d ",mat[i][j]);
// 			zigzag('d',i+1,j-1);
// 		}
// 	}
// 	else if (a=='u'){
// 		if (i==0){
// 			printf("%d ",mat[i][j]);
// 			zigzag('d',i,j+1);
// 		}
// 		else if (j==n-1){
// 			printf("%d ",mat[i][j]);
// 			zigzag('d',i+1,j);
// 		}
// 		else {
// 			printf("%d ", mat[i][j]);
// 			zigzag('u',i-1,j+1);
// 		}
// 	}
// }

int main (){
	scanf("%d %d",&m, &n);
	char com[20];
	scanf("%s",com);
	for (int i=0; i<m ;i++){
		for (int j=0; j<n; j++){
			scanf("%d",&mat[i][j]);
		}
	}
	if (n==1 || m==1){
		for (int i=0; i<m; i++){
			for (int j=0; j<n; j++)printf("%d ",mat[i][j]);
		}
		printf("\n");
		return 0;
	}
	// if (com[0]== 'Z'){
	// 	printf("%d %d", mat[0][0], mat[0][1]);
	// 	zigzag('d', 1,0);
	// }
	if(com[0]=='L'){
		printf("%d ", mat[0][0]);
		leftright(1,0,1);
	}
	// else {
	// 	printf("%d ", mat[0][0]);
	// 	updown('d',0,0);
	// }
	return 0;
}