#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool cmp(const pair<int, char> &a, const pair<int, char> &b) {
    return a.first > b.first;
}

int main() {
    int n, k;
    cin >> n >> k;
    string v;
    cin >> v;

    string a = v, pre;
    int cnt = 0;
    vector<pair<int, char> > m;
    for (int i = 0; i < 26; i++) {
        cnt = ranges::count(v, 'a' + i);
        if (cnt != 0) m.emplace_back(cnt, 'a' + i);
    }
    ranges::sort(m, cmp);
    // for (int i = 0; i < m.size(); i++) {
    //     cout << m[i].first;
    // }
    long long ans = 0;
    for (int i = 0; i < m.size(); i++) {
        if (k) {
            if (m[i].first >= 3) {
                k--;
                continue;
            }
        }
        ans += m[i].first;
    }
    cout << ans;
}