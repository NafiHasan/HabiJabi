#include <stdio.h>

int strcomp(char a[], char b[]){
	for (int i=0; b[i]!=' ' || b[i]!='\0' || a[i]!=' '||a[i]!='\0'; i++){
		if(a[i]>b[i])return 1;
		else if (a[i]<b[i])return 0;
	}
	return 0;
}
int strcpy()
int main()
{
	char s;
	char ara[105][105];
	int i=0,cnt=0;
	while(1){
		printf ("r");
		s=getchar();
		if(s==EOF){
			ara[i][cnt]=' ';
			i++;
			break;
		}
		if (s==' '){
			ara[i][cnt]=' ';
			cnt=0;
			i++;
			continue;
		}
		if((s>=65 && s<91) || (s>=97 && s<123)) ara[i][cnt++]=s;
	}
	for (int j=0; j<i ;j++){
		for (int k=0; ara[j][k]!=' '; k++)printf("%c",ara[j][k]);
		printf("\n");
	}
	for (int j=0; j<i-1; j++){
		for (int k=j+1; k<j; k++){
			if (strcomp(ara[j],ara[k])==0){
				char tmp[]=
			}
		}
	}
    return 0;
}