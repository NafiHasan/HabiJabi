#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"


int main ()
{
    // ios::sync_with_stdio(false); 
    // cin.tie(NULL);
    
    w(t){
        int n,m;
        cin >>n>>m;
        int ara[n][m];
        for (int i=0; i<n; i++){
            string s;
            cin >>s;
            for (int j=0; j<m; j++){
                ara[i][j]=s[j]-'0';
            }
        }
        vector <vector<int>>v;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (ara[i][j]==1){
                    int sum=0,x1=i,x2=i,x3=i+1,x4=i+1,y1=j,y2=j+1,y3=j,y4=j+1;
                    if (i==n-1 && j!=m-1)x3=x4=i-1;
                    else if (j == m - 1 && i != n - 1)
                        y2 = y4 = j - 1;
                    else if (i==n-1 && j==m-1){
                        y2 = y4 = j - 1;
                        x3 = x4 = i - 1;
                    }
                    sum=ara[x1][y1]+ara[x2][y2]+ara[x3][y3]+ara[x4][y4];
                    vector<int>tmp(6);
                    if (sum==1){
                        ara[x1][y1]=0;
                        tmp={x1,y1,x3,y3,x4,y4};
                        v.push_back(tmp);
                        tmp={x1,y1,x2,y2,x3,y3};
                        v.push_back(tmp);
                        tmp={x1,y1,x2,y2,x4,y4};
                        v.push_back(tmp);
                        tmp.clear();
                    }
                    else if (sum==4){
                        ara[x1][y1]=ara[x3][y3]=ara[x4][y4]=0;
                        tmp={x1,y1,x3,y3,x4,y4};
                        v.push_back(tmp);
                        // tmp = {x1, y1, x3, y3, x4, y4};
                        // v.push_back(tmp);
                        // tmp = {x1, y1, x2, y2, x3, y3};
                        // v.push_back(tmp);
                        // tmp = {x1, y1, x2, y2, x4, y4};
                        // v.push_back(tmp);
                        tmp.clear();
                    }
                    else if (sum==3){
                        tmp.clear();
                        if (ara[x1][y1]==1){
                            tmp.push_back(x1);
                            tmp.push_back(y1);
                            ara[x1][y1]=0;
                        }
                        if (ara[x2][y2] == 1)
                        {
                            tmp.push_back(x2);
                            tmp.push_back(y2);
                            ara[x2][y2] = 0;
                        }
                        if (ara[x3][y3] == 1)
                        {
                            tmp.push_back(x3);
                            tmp.push_back(y3);
                            ara[x3][y3] = 0;
                        }
                        if (ara[x4][y4] == 1)
                        {
                            tmp.push_back(x4);
                            tmp.push_back(y4);
                            ara[x4][y4] = 0;
                        }
                        v.push_back(tmp);
                        ara[x1][y1]=ara[x2][y2]=ara[x3][y3]=ara[x4][y4]=0;
                        tmp.clear();
                    }
                    else {
                        int culx,culy;
                        if (ara[x2][y2]==1){
                            culx = x2;
                            culy=y2;
                        }
                        else if (ara[x3][y3]==1){
                            culx = x3;
                            culy = y3;
                        }
                        else {
                            culx = x4;
                            culy = y4;
                        }
                        tmp={x2,y2,x3,y3,x4,y4};
                        v.push_back(tmp);
                        tmp.clear();
                        if (culx==x2 && culy==y2){
                            tmp={x1,y1,x3,y3,x4,y4};
                        }
                        else if (culx==x4 && culy==y4){
                            tmp={x1,y1,x2,y2,x3,y3};
                        }
                        else tmp={x1,y1,x2,y2,x4,y4};
                        v.push_back(tmp);
                        ara[x1][y1]=ara[x2][y2]=ara[x3][y3]=ara[x4][y4]=0;
                    }
                }
            }       
        }
        cout <<v.size()<<en;
        for (int i=0; i<v.size(); i++){
            for (int j=0; j<6; j++)cout <<v[i][j]+1<<" ";
            cout <<en;
        }
    }
    return 0;
}