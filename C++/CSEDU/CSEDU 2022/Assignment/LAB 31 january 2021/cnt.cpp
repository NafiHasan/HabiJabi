#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    char c;
    int cnt[30];
    memset(cnt,0,sizeof(cnt));
    while(cin >> c){
        if (c >= 97 && c<=122)cnt[c-97]++;
    }   
    for (int i=0; i<27; i++)cout << char(i+97) << " " << cnt[i] << en;
    return 0;
}