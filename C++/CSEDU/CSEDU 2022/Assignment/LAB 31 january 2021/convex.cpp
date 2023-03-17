#include <stdio.h>
int main (){
	int n;
	scanf("%d",&n);
	int x[n+1],y[n+1];
	for (int i=0; i<n; i++){
		scanf("%d %d", &x[i], &y[i]);
	}
	x[n]=x[0],y[n]=y[0];
	int got=0;
	bool ans=1;
	for (int i=2; i<=n; i++){
		double slope1,slope2;
		if (x[i]!=x[i-1]) slope1= (double)(y[i]-y[i-1]) / (x[i]-x[i-1]);
		else slope1=100000000.0;
		if (x[i-1] != x[i-2]) slope2 = (double)(y[i-1]-y[i-2]) / (x[i-1]-x[i-2]);
		else slope2=100000000.0;
		printf("%lf %lf\n",slope1 , slope2);
		if (i==2){
			if (slope1>=slope2)got=1;
			else got=0;
		}
		else if (got == 1 && slope2 >= slope1)got=0;
		else if(got == 0 && slope1 >= slope2) got=1;
		else {
			printf("%d %lf %lf\n",i ,slope1 , slope2);
			ans=false;
			break;
		}
	}
	if (ans) printf("Convex polygon exists\n");
	else printf ("No convex polygon possible\n");
}