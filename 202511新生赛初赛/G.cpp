#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n,t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        cin >> n;
        vector<int> v(n+1);
        v[0] = n+1;
        for(int j = 1;j <= n;j++) {
            cin >> v[j];
        }
        if(n%2==0) {
            cout << -1 << "\n";
        }
        else {
            int temp;
            bool flag = true;
            vector<long long> pre(n+1);
            pre[0] = n+1;
            for (int j = 1;j <= n;j++) {
                pre[j] = pre[j-1]+v[j];
            }
            set<int> s;
            s.emplace(0);
            for (int j = 1;j <= n;j++) {
                temp = pre[j]%(n+1);
                if(s.contains(temp)) {
                    cout << -1;
                    flag = false;
                    break;
                }
                else {
                    s.emplace(temp);
                }
            }
            if(flag) {
                for (int j = 0;j <= n;j++) {
                    cout << v[j] << " ";
                }
            }
            cout << "\n";
        }
    }
}