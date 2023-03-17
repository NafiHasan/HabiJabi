#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2){
        int dif= abs(y1-y2);
        x3=x1+dif;
        x4=x1+dif;
        y3=y1;
        y4=y2;
        cout << x3 << " " << y3 << " " << x4 << " " << y4<< "\n";
    }
    else if (y1==y2){
        int dif = abs(x1 - x2);
        y3 = y1 + dif;
        y4 = y1 + dif;
        x3 = x1;
        x4 = x2;
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
    }
    else {
        x3=x2;
        x4=x1;
        y3=y1;
        y4=y2;
        if(abs(x3-x1) == abs(y2-y3))
            cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
        else cout <<"-1\n";
    }
    return 0;
}