#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"

char get(char s[], int index){
    int j=0;
    if (index>strlen)return s[0];
    get(s,index-1);
    cout <<s[]
    return s[0];
}

int main ()
{
    char s[1000];
    cin >>s;
    int len=strlen(s);
    get(s,len);
    cout <<s<<endl;
    return 0;
}