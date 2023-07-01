#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
#define en "\n"
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define w(t) int t; cin >> t; while (t--)
 
int main()
{
	fast_io();
 	w(t){
 		int n;
 		cin >>n;
 		int b[n];
 		map<int,int>m1,m2;
 		vector<int>a(n);
 		for (int i=0; i<n; i++){
 			cin >> b[i];
 			m1[b[i]]++;
 			m2[b[i]]++;
 			a[i]=b[i];
 			if(i && b[i]==b[i-1])a[i]=0;
 		}
 		vector<int>mx(n),mn(n);
 		for (int i=0; i<n; i++){
 			if (a[i]){
 				mx[i]=a[i];
 				int num=a[i];
 				for (int j=i+1; j<n; j++){
 					if(a[j])break;
 					num--;
 					while(m1[num]!=0)num--;
 					mx[j]=num;
 					m1[num]++;
 				}
 			}
 		}
 		int lo=1;
 		for (int i=0; i<n; i++){
 			if (a[i]){
 				mn[i]=a[i];
 				int num=a[i];
 				for (int j=i+1; j<n; j++){
 					if(a[j])break;
 					num=lo;
 					while(m2[num]!=0){
 						num++;
 						lo++;
 					}
 					mn[j]=num;
 					m2[num]++;
 				}
 			}
 		}
 		for (int i=0 ;i<n; i++)cout << mn[i] << " ";
 		cout << en;
 		for (int i=0 ;i<n; i++)cout << mx[i] << " ";
 		cout <<en;
 	}	
    return 0;
}
