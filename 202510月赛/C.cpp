#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, c = 0, pre = 0, num = 1;
        cin >> l;
        vector<int> v;
        if (l == 1) {
            cout << "! 1" << endl;
            continue;
        }
        cout << "?" << " ";
        for (int i = 0; i < l; i++) {
            cout << l + 1 << " ";
        }
        do {
            cin >> c;
            if (c == l) {
                v.emplace_back(num - 1);
                break;
            }
            if (c == pre + 1) {
                v.emplace_back(num - 1);
                pre = c;
                num = 1;
            }
            cout << "?" << " ";
            for (int i = 0; i < pre; i++) {
                cout << v[i] << " ";
            }
            cout << num << " ";
            for (int i = pre + 1; i < l; i++) {
                cout << l + 1 << " ";
            }
            num++;
            cout << endl;
        } while (c != l);
        cout << "!" << " ";
        for (int i = 0; i < l; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}