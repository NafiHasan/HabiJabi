#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;

#define ll long long
#define db double
#define pb push_back
#define popb pop_back
#define eb emplace_back
#define pf push_front
#define popf pop_front
#define ef emplace_front
#define vi vector<int>
#define vs vector<string>
#define vL vector<ll>
#define vc vector<char>
#define vb vector<bool>
#define vvL vector<vector<ll>>
#define vvc vector<vector<char>>
#define pLL pair<ll, ll>
#define umap unordered_map
#define sz(x) x.size()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repb(i, n) for (ll i = 1; i <= n; i++)
#define rrep(i, n) for (ll i = n; i >= 0; i--)
#define rrepb(i, n) for (ll i = n; i > 0; i--)
#define EACH(x, a) for (auto &x : a)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vsort(v) sort(all(v))
#define vsortr(v) sort(rall(v))
#define cpresent(c, x) ((c).find(x) != (c).end())
#define vpresent(c, x) (find(all(c), x) != (c).end())
#define sqr(x) (x * x)

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

const double PI = acos(-1.0);
// const long long mxN;
// const long long mod = 1e9 + 7;
void solve();

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}

void fileIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int cs;

db findArea(db a, db b, db c)
{
    db s = (a + b + c) / (db)2;
    db area = s * (s - a) * (s - b) * (s - c);
    return sqrt(area);
}

int main()
{
    fastIO();
    fileIO();
    // solve(); /*
    int t;
    cin >> t;
    for (cs = 1; cs <= t; cs++)
    {
        // printf("Case %d: ", cs);
        solve();
    }
    // */
    return 0;
}

void solve()
{
    ll N;
    cin >> N;
    vector<db> v(N + 1);
    for (ll i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end() - 1);
    v[N] = DBL_MAX;
    debug(v);
    db ans = DBL_MAX;
    bool found = 0;
    ll i = 0, j, k;
    while (i < N)
    {
        ll l = i + 1, r = N, m;
        while (l < r - 1)
        {
            m = (l + r) / 2;
            debug(m);
            if (v[m] < v[i] + v[i + 1])
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        if (l != i + 1)
        {
            found = 1;
            for (k = i + 1; k < l; k++)
            {
                if (v[k] + v[i] > v[l])
                {
                    ans = min(findArea(v[i], v[k], v[l]), ans);
                }
            }
        }
        i++;
    }
    if (found)
    {
        cout << ans << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
    return;
}