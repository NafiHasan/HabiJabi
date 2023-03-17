#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fast_io();
    string ans = "";
    char a = '0', b = '0';
    int val;
    for (char i = 'a'; i <= 'z'; i++) {
        cout << "ASK " << i << endl;
        cin >> val;
        if (val == 1) {
            if (a == '0')a = i;
            else {
                b = i;
                break;
            }
        }
    }
    string tmp = "";
    tmp = a;
    tmp += b;
    cout << "ASK " << tmp << endl;
    cin >> val;
    if (val == 0) {
        tmp = b;
        tmp += a;
    }
    ans = tmp;
    bool lat = 1;
    for (int i = 0; ; i++) {
        char now;
        if (i % 2 == 0)now = a;
        else now = b;
        if (lat) {
            cout << "ASK " << ans + now << endl;
            cin >> val;
            if (val == 1) {
                ans += now;
            } else {
                if (now == a)now = b;
                else now = a;
                cout << "ASK " << ans + now << endl;
                cin >> val;
                if (val == 1) {
                    ans += now;
                } else lat = 0;
            }
        } else {
            tmp = now + ans;
            cout << "ASK " << tmp << endl;
            cin >> val;
            if (val == 1) {
                ans = now + ans;
            } else {
                if (now == a)now = b;
                else now = a;
                tmp = now + ans;
                cout << "ASK " << tmp << endl;
                cin >> val;
                if (val == 1) {
                    ans = now + ans;
                } else {
                    cout << "ANSWER " << ans << endl;
                    return 0;
                }
            }
        }

    }
    return 0;
}