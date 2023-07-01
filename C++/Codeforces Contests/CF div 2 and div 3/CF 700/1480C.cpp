#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

int ara[100010];
bool found =false;
int rec(int lo, int hi){
    if (lo>hi || found)return 0;
    int mid = (lo + hi) / 2;
    int a, b, c;
    if (ara[mid-1]==-1){
        cout << "? " << mid - 1 << en;
        cin >> a;
        ara[mid-1]=a;
    }
    else a=ara[mid-1];
    if (ara[mid]==-1){
        cout << "? " << mid << en;
        cin >> b;
        ara[mid]=b;
    }
    else b=ara[mid];
    if (ara[mid+1]==-1){
        cout << "? " << mid + 1 << en;
        cin >> c;
        ara[mid+1]=c;
    }
    else c=ara[mid+1];
    if (b < a && b < c)
    {
        cout << "! " << mid << endl;
        found =true;
        return 1;
    }
    else {
        if (!found)rec(lo, mid-1);
        if(!found) rec(mid + 1, hi);
    }
    return 0;
}

int main ()
{
    // ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >>n;
    if (n==1){
        cout <<"! 1"<<endl;
        found =true;
    }
    for (int i=0; i<100010; i++)ara[i]=-1;
    if (!found){
        cout << "? " << n << endl;
        int x, y;
        cin >> x;
        ara[n] = x;
        cout << "? " << n - 1 << endl;
        cin >> y;
        ara[n - 1] = y;
        if (x < y){
            cout << "! " << n << endl;
            found = true;
            return 0;
        }
    }
    if (!found){
        int x,y;
        cout << "? " << 1 << endl;
        cin >> x;
        ara[1] = x;
        cout << "? " << 2 << endl;
        cin >> y;
        ara[2] = y;
        if (x < y){
            cout << "! 1" << endl;
            found = true;
            return 0;
        }
    }
    if (n==3){
        cout <<"? "<<2<<endl;
        int x;
        cin >>x;
        if (x==1){
            cout << "! 2" << endl;
            found =true;

        }
    }
    else {
        if (!found) rec(2,n/2);
        if (!found)
            rec(n / 2 + 1, n-1);
    }
    return 0;
}