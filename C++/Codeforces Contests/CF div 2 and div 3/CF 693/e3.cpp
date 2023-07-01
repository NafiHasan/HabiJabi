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
        cin >> n;
        vector<pair<pair<int,int>,int>>v(n);
        map<pair<int,int>,int>m;
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x>> y;
            if (x>y)swap(x,y);
            v[i]={{x,y},i};
        }
        sort(v.begin (), v.end());
        vector<pair<pair<int,int>,int>>temp;
        int crnt=v[0].first.first;
        temp.push_back({{v[0].first.first,v[0].first.second},v[0].second});
        vector<int>ans(n,-1);
        int mn=INT_MAX, sec=INT_MAX;
        for(int i=1; i<n; i++){
            if(v[i].first.first != crnt){
                crnt =v[i].first.first;
                for(int j=0; j<temp.size(); j++){
                    if (mn>temp[j].first.second){
                        mn=temp[j].first.second;
                        sec=temp[j].second;
                    }
                }
                temp.clear();
                temp.push_back({{v[i].first.first,v[i].first.second},v[i].second});
                if(mn!=INT_MAX && v[i].first.second > mn) 
                    ans[v[i].second]=sec+1;
            }
            else {
                if (mn!=INT_MAX && v[i].first.second > mn)
                    ans[v[i].second] = sec + 1;
                temp.push_back({{v[i].first.first,v[i].first.second},v[i].second});
            }
        }
        for(int i=0; i<n; i++)cout << ans[i]<< " ";
        cout << en;
    }   
    return 0;
}