#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    string a,b;
    cin >> a >> b;
    int cnt=0;
    char c1,c2;
    if (a.size() != b.size()){
        cout << "NO\n";
        return 0;
    }
    bool ans=true;
    for (int i=0; i<a.size(); i++){
        if (cnt>2)break;
        if (cnt==0 && a[i]!=b[i]) {
            cnt++;
            c1=b[i];
            c2=a[i];
        }
        else if (cnt==1 && a[i]!=b[i]){
            cnt++;
            if (a[i] != c1 || b[i] != c2)ans=false;
        }
        else if (a[i]!=b[i])cnt++;
    }
    if (cnt!=2 || ans==false)cout << "NO\n";
    else cout << "YES\n";
    return 0;
}