#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    #ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
  freopen ("output.txt", "w", stdout);
  #endif
    int t;
    scanf("%d", &t);
   for(int tc = 1; tc <= t; tc++)
   {
       long long int x1, y1, x2, y2;
       scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
       ll a = (x1+x2)*max(y1,y2);
       ll b = (x1+y2)*max(x2,y1);
       ll c = (y1+x2)*max(x1,y2);
       ll d = (y1+y2)*max(x1,x2);
       ll arr[4] = {a,b,c,d};
       sort(arr,arr+4);
       ll area;
       if(arr[0]==a){
           area = 2*a+(x1*min(y1,y2))-(x1*max(y1,y2));
       }
       else if(arr[0]==b){
           area = 2*b+(x1*min(x2,y1))-(x1*max(y1,x2));
       }
       else if(arr[0]==c){
           area = 2*c+(y1*min(y2,x1))-(y1*max(x1,y2));
       }
       else
       {
           area = 2*c+(y1*min(x2,x1))-(y1*max(x1,x2));
       }
       if(area%2==0){
           printf("Case %d: %lld.0\n",tc,area/2);
       }
       else
       {
           printf("Case %d: %lld.5\n",tc,area/2);
       }
       
   }
}