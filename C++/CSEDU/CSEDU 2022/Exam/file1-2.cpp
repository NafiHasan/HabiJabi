#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	fp = fopen("program.txt", "r");

	// error check

	int n;
	fscanf(fp, "%d", &n);
	printf("%d\n", n);
	fclose(fp);
	return 0;
}