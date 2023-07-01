#include <bits/stdc++.h>   

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int> , null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
	fast_io();
 	int tc;
 	cin >> tc;
 	while(tc--){
 		int n;
 		cin >> n;
 		ordered_set s;
 		long long ans =0;
 		for(int i=0; i<n; i++){
 			int x;
 			cin >> x;
 			int les = s.order_of_key({x,0});
 			int grt = i - s.order_of_key({x+1,0});
 			ans += min(les, grt);
 			s.insert({x,i}); 
 		}
 		cout << ans << '\n';
 	}
    return 0;
}