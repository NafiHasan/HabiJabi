#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    string s1,s2;
    cin >> s1 >> s2;
    int ans=0;
    for(int i=0; i<s1.size(); i++){
        int num1, num2;
        if(s1[i]<95)num1=s1[i]-65;
        else num1=s1[i]-97;
        if (s2[i] < 95)
            num2 = s2[i] - 65;
        else
            num2 = s2[i] - 97;
        if(num1<num2){
            ans=-1;
            break;
        }
        else if(num1>num2){
            ans=1;
            break;
        }
    }   
    cout << ans << "\n";
    return 0;
}