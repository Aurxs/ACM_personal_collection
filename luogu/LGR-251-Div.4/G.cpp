#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    string s;
    cin >> s;
    stack<char> s1;
    stack<long long> value;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == 'a' || c == 'b') {
            s1.push(c);
        }
        else if (c >= '0' && c <= '9') {
            long long x = 0;
            while (s[i] != ']') {
                x = x * 10 + (s[i] - '0');
                i++;
            }
            value.push(x);
            i--;
        }
        else if (c == ']') {
            if (!s1.empty() && !value.empty()) {
                char temp = s1.top();
                s1.pop();
                long long val = value.top();
                value.pop();
                long long pre;
                if (temp == 'a') pre = a[val];
                else pre = b[val];
                value.push(pre);
            }
        }
    }
    if (!value.empty()) {
        cout << value.top() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}