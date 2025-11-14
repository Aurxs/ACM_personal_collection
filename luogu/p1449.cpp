#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    int a = 0, b = 0, i, j;
    stack<int> st;
    cin >> s;
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it == '@') break;
        else if (*it == '.') {
            st.push(a);
            b = 0, a = 0;
        }
        else if (*it <= '9' && *it >= '0') {
            a = b * 10 + *it - '0';
            b = a;
        }
        else {
            if (*it == '-') {
                i = st.top();
                st.pop();
                j = st.top();
                st.pop();
                st.push(j - i);
            }
            else if (*it == '+') {
                i = st.top();
                st.pop();
                j = st.top();
                st.pop();
                st.push(j + i);
            }
            else if (*it == '*') {
                i = st.top();
                st.pop();
                j = st.top();
                st.pop();
                st.push(j * i);
            }
            else if (*it == '/') {
                i = st.top();
                st.pop();
                j = st.top();
                st.pop();
                st.push(j / i);
            }
        }
    }
    cout << st.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}