#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fptr;
	fptr = fopen("program.txt", "a");

	if(fptr == NULL){
		printf("null");
		exit(1);
	}
	int n;
	scanf("%d", &n);

	fprintf(fptr, "%d\n", n);
	fclose(fptr);
	return 0;
}