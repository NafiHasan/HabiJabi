#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int remove(int s,int x){
    s=((~(1<<(x-1))) &s);
    return s;
}

void display(int s){
    for (int i=0; i<30; i++){
        if ((1<<i) &s)cout <<i+1<<en;
    }
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int s;
    cin >>s;
    s=remove (s,2);
    display(s);   
    return 0;
}