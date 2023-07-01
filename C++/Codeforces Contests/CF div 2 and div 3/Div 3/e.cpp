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
 		set<int , greater<int>>s1;
 		set <int> s2;
 		vector<int>a(n);
 		for (int i=1; i<=n; i++){
 			s1.insert(i);
 			s2.insert(i);
 		}
 		for (int i=0; i<n; i++){
 			cin >> b[i];
 			a[i]=b[i];
 			s1.erase(b[i]);
 			s2.erase(b[i]);
 			if(i && b[i]==b[i-1]){
 				a[i]=0;
 			}
 		}
 		int cnt=0;
 		vector<int>mx(n),mn(n);
 		for (int i=0; i<n; i++){
 			if (a[i]){
 				mx[i]=a[i];
 				int num=a[i];
 				for (int j=i+1; j<n; j++){
 					if(a[j])break;
 					num=*s1.upper_bound(num);
 					s1.erase(num);
 					mx[j]=num;
 					i=j;
 				}
 			}
 		}
 		for (int i=0; i<n; i++){
 			if (a[i]){
 				mn[i]=a[i];
 				int num=a[i];
 				for (int j=i+1; j<n; j++){
 					if(a[j])break;
 					num=*s2.upper_bound(0);
 					s2.erase(num);
 					mn[j]=num;
 					i=j;
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