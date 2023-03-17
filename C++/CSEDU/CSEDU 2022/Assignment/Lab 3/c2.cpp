#include <stdio.h>

void rec(char s[], int n){
	if (n==0){
		printf("%s",s);
		return ;
	}
	for (int i=0; s[i]!='\0' ; i++){
		if (n%2 && s[i]=='1'){
			rec(s,n-1);
		}
		else if(n%2==0 && s[i]=='0'){
			rec(s,n-1);
		}
		else printf("%c",s[i]);
	}
}


int main(){
	char s[5];
	int x;
	scanf("%s %d",s, &x);	
	rec(s,x);
	printf ("\n");
	return 0;
}