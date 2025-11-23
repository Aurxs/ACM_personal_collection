#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0;i<n;i++) {
        int t;
        cin >> t;
        v[i] = t%3;
    }
    for (int i = 0;i<q;i++) {
        int l,r;
        cin >> l >> r;
        int cntone = 0,cnttwo = 0;
        bool flag = false;
        for (int j = l-1;j<r;j++) {
            if (v[j]==0) {
                cout << "YES" << "\n";
                flag = true;
                break;
            }
            if (v[j] == 1) {
                cntone++;
            }
            else {
                cnttwo++;
            }
            if (cntone>=3||cnttwo>=6) {
                cout << "YES" << "\n";
                flag = true;
                break;
            }
            if (cntone>=1&&cnttwo>=1) {
                cout << "YES" << "\n";
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "No" << "\n";
        }
    }
    return 0;
}