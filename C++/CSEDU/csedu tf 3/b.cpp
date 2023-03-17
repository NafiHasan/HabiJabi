#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int tt,c=1;
    scanf("%d",&tt);
    getchar();
    //cout <<tt<<en;
    char s[100000];
    while(tt--){
        gets(s);
        map<char,int>m;
        for (int i='a',j=1; i<='r'; i++,j++)m[i]=j;
        for (int i='a',j=1; i<='r'; i++,j++){
            if (m[i]%3==0)m[i]=3;
            else m[i]=j%3;
        }
        m['s']=4,m['z']=4;
        m[' ']=1;
        for (int i='t',j=1;i<='y'; i++,j++)m[i]=j;
        for (int i='t',j=1; i<='y'; i++,j++){
            if (m[i]%3==0)m[i]=3;
            else m[i]=j%3;
        }
        int ans=0;
        for (int i=0; i<strlen(s); i++){
            //cout <<s[i]<<" "<<m[s[i]]<<en;
            ans+=m[s[i]];
        }
        cout << "Case #"<<c++<<": "<<ans<<en;
    }   
    return 0;
}