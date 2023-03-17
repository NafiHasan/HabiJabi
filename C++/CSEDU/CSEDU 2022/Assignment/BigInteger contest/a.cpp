//A integer inquiry

#include <stdio.h>

int strlen(char s[]){
	int ans=0;
	for (int i=0; s[i] != '\0'; i++)ans++;
	return ans;
}


int main(){
	char s[110];
	int ans[110];
	for (int i=0; i<110; i++)ans[i]=0;
	while(1){
		scanf("%s",s);
		if(s[0] == '0' && strlen(s) == 1)break;
		int len = strlen(s);
		char temp[len];
		for (int i=len-1, j=0; i>=0; j++,i--)temp[j] = s[i]-'0';
		int carry=0,i=0;
		while (1){
			if(carry == 0 && i > len)break;
			int t=0;
			if(i<len)t=temp[i];
			int tmp = ans[i] + t + carry;
			carry = 0;
			if(tmp > 9) {
				carry = tmp / 10;
				tmp = tmp % 10;
			}
			ans[i] = tmp;
			i++;
		}
		// for (int j=0; j<10; j++)printf("%d",ans[j]);
		// printf("\n");
		if(carry > 0) ans[i] += carry;
	}
	int dig=0;
	for (int j=0; j<110 ;j++)if(ans[j] != 0)dig = j;
	for (int j= dig; j>=0; j--)printf("%d",ans[j]);
	printf("\n");
	return 0;
}