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
    
    w(t){
        int x1, x2, x3, x4, y1, y2, y3, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        int hiy = max({y1, y2, y3, y4}), loy = min({y1, y2, y3, y4});
        int hi = hiy - loy;
        int hix = max({x1, x2, x3, x4}), lox = min({x1, x2, x3, x4});
        int wid = hix - lox;
        int sq = min(hi, wid);
        int a1 = lox, b1 = loy, a2 = lox, b2 = hiy, a3 = hix, b3 = loy, a4 = hix, b4 = hiy;
        int cnt1 = 0,cnt2=0;
        char prev = 'u';
        if (1){
            if (hi > wid)
            {
                int mvd = (hi - wid);
                b1 += mvd, b3 += mvd;
            }
            else if (hi < wid)
            {
                int mvd = (wid - hi);
                a1 += mvd, a3 += mvd;
            }
            vector<pair<int, int>> des;
            vector<pair<int, int>> cur;
            cur.push_back(make_pair(x1, y1));
            cur.push_back(make_pair(x2, y2));
            cur.push_back(make_pair(x3, y3));
            cur.push_back(make_pair(x4, y4));
            des.push_back(make_pair(a1, b1));
            des.push_back(make_pair(a2, b2));
            des.push_back(make_pair(a3, b3));
            des.push_back(make_pair(a4, b4));
            for (int i = 0; i < 4; i++)
                cout << des[i].first << " " << des[i].second << en;
            vector<int> v;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    int p = abs(des[i].first - cur[j].first) + abs(des[i].second - cur[j].second);
                    v.push_back(p);
                }
            }
            // for (int i = 0; i < v.size(); i++)
            //     cout << v[i] << " ";
            cnt1 = INT_MAX;
            int dist;
            for (int i = 0; i < 4; i++)
            {
                dist = v[i];
                //cout <<"i "<<dist<<en;
                for (int j = 4; j < 8; j++)
                {
                    if ((j - i) % 4 != 0)
                    {
                        dist = v[i] + v[j];
                        //cout<<"j " <<dist<<en;
                        for (int k = 8; k < 12; k++)
                        {
                            if ((k - j) % 4 != 0 && (k - i) % 4 != 0)
                            {
                                dist = v[i] + v[j] + v[k];
                                //cout << "k " << dist << en;
                                for (int l = 12; l < 16; l++)
                                {
                                    if ((l - k) % 4 != 0 && (l - j) % 4 != 0 && (l - i) % 4 != 0)
                                    {
                                        dist = v[i] + v[j] + v[k] + v[l];
                                        //cout << i << " " << j << " " << k << " " << l << " " << dist << en;
                                        cnt1 = min(cnt1, dist);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (1){
            if (hi > wid)
            {
                int mvd = (hi - wid);
                b1-=mvd, b3-=mvd;
                b2 -= mvd, b4 -= mvd;
            }
            else if (hi < wid)
            {
                int mvd = (wid - hi);
                a1-=mvd, a3-=mvd;
                a2 -= mvd, a4 -= mvd;
            }
            vector<pair<int, int>> des;
            vector<pair<int, int>> cur;
            cur.push_back(make_pair(x1, y1));
            cur.push_back(make_pair(x2, y2));
            cur.push_back(make_pair(x3, y3));
            cur.push_back(make_pair(x4, y4));
            des.push_back(make_pair(a1, b1));
            des.push_back(make_pair(a2, b2));
            des.push_back(make_pair(a3, b3));
            des.push_back(make_pair(a4, b4));
            for (int i = 0; i < 4; i++)
                cout << des[i].first << " " << des[i].second << en;
            vector<int> v;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    int p = abs(des[i].first - cur[j].first) + abs(des[i].second - cur[j].second);
                    v.push_back(p);
                }
            }
            //for (int i = 0; i < v.size(); i++)
               // cout << v[i] << " ";
            cnt2 = INT_MAX;
            int dist=0;
            for (int i = 0; i < 4; i++)
            {
                dist = v[i];
                //cout <<"i "<<dist<<en;
                for (int j = 4; j < 8; j++)
                {
                    if ((j - i) % 4 != 0)
                    {
                        dist = v[i] + v[j];
                        //cout<<"j " <<dist<<en;
                        for (int k = 8; k < 12; k++)
                        {
                            if ((k - j) % 4 != 0 && (k - i) % 4 != 0)
                            {
                                dist = v[i] + v[j] + v[k];
                                //cout << "k " << dist << en;
                                for (int l = 12; l < 16; l++)
                                {
                                    if ((l - k) % 4 != 0 && (l - j) % 4 != 0 && (l - i) % 4 != 0)
                                    {
                                        dist = v[i] + v[j] + v[k] + v[l];
                                        //cout << i << " " << j << " " << k << " " << l << " " << dist << en;
                                        cnt2 = min(cnt2, dist);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << min(cnt1,cnt2) << en;
    }
    return 0;
}