#include <bits/stdc++.h>   
using namespace std;
 
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
 	set<int> s;
 	s.insert(1);	
 	s.insert(5);	
 	s.insert(7);	
 	s.insert(12);
 	s.insert(16);
 	if(s.lower_bound(16) != s.end())cout << *s.lower_bound(16) << '\n';	
    return 0;
}