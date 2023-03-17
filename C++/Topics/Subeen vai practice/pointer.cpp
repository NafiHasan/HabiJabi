#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    char c= 'A';
    char *p , **q;

    p= &c;
    q = &p;

    **q= 'B' ;

    printf("Value of c: %c\n", c);   // B
    printf("Value of c: %c\n", *p);  //B
    printf("Value of c: %c\n", **q);   //B
    
    return 0;
}