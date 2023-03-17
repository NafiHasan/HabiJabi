#include <stdio.h>  

int main()
{
 	int n;
 	scanf("%d", &n);
 	int a[n];
 	for (int i=0; i<n; i++)scanf("%d",&a[i]);
 	bool no=0, orr=0, andd=0, ans=1;
 	char c;
 	while (1){
 		c=getchar();
 		if (c==EOF)break;
 		if (c == ' ')continue;
 		else if (c == '.')andd=1;
 		else if (c == '+') orr=1;
 		else if (c == '~') no=1;
 		else if(c>64 && c<80){
 			bool val=a[c-65];
 			if (no)val=1-val;
 			if(orr){
 				ans |= val;
 				orr=0;
 			}
 			else if (andd){
 				ans &= val;
 				andd=0;
 			}
 			else ans=val;
 		}
 		else if (c == '('){
 			bool tmp=true;
 			char op1='n',op2='n', prev='n';
 			while (1){
 				char d;
 				d= getchar();
 				if (d==' ')continue;
 				if (d==')'){
 					if (no){
 						tmp = ~tmp;
 						no=0;
 					}
 					if (orr){
 						ans |= tmp;
 						orr=0;
 					}
 					else if (andd) {
 						ans &= tmp;
 						andd=0;
 					}
 					else ans = tmp; 
 					break;
 				}
 				else if (d == '+' || d == '.') op1 = d;
 				else if (d=='~') op2='~';
 				else if (d>64 && d<80){
 					bool val=a[d-65];
 					if (op2=='~'){
 						op2='n';
 						val = 1-val;
 					}
 					if (op1!='n'){
 						if (op1=='+')tmp |= val;
 						else if (op1 == '.') tmp &= val;
 					}
 					else tmp = val;
 				}
 			}
 		}
 	}	
 	if (ans)printf("True\n");
 	else printf("False\n");
    return 0;
}