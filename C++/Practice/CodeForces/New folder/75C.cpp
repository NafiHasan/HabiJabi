#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    vector<int>v;
    vector<int>div;
    map<int,int>m;
    map<int,int>done;
    for(int i=1; i*i<=a; i++){
        if (a % i == 0){
            div.push_back (i);
            m[i]++;
            if( i!= a/i ) {
                div.push_back(a / i);
                m[a/i]++;
            }
        }
    }
    for (int i = 1; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            div.push_back(i);
            m[i]++;
            if (i != b / i)
            {
                div.push_back(b / i);
                m[b / i]++;
            }
        }
    }
    sort(div.begin (), div.end());
    v.push_back(div[0]);
    done[div[0]]++;
    for(int i=1; i<div.size(); i++){
        if(done[div[i]]==0 && m[div[i]]>=2){
            v.push_back(div[i]);
            done[div[i]]++;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        bool found=false;
        for(int i=v.size()-1; i>=0 ; i--){
            if(v[i] >= l && v[i] <= r){
                cout << v[i] << en;
                found = true;
                break;
            }
        }
        if (!found) cout <<"-1\n";
    }
    return 0;
}