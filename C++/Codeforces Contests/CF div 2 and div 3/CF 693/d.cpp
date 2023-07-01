#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n;
        cin >>n;
        priority_queue<int>q;
        for (int i=0; i<n; i++){
            int x;
            cin >>x;
            q.push(x);
        }
        ll a=0,b=0;
        int play=1;
        while(!q.empty()){
            int top=q.top();
            q.pop();
            if (top%2==1 && play==2)b+=top;
            else if (top%2==0 && play==1)a+=top;
            if (play==1)play=2;
            else play=1;
        }
        if(a>b)cout <<"Alice\n";
        else if (a<b)cout <<"Bob\n";
        else cout <<"Tie\n";
    }
    return 0;
}