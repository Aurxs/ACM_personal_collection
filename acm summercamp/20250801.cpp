#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    while (a--) {
        int n;
        long long V;
        cin >> n >> V;
        long long total_w = 0, total_v = 0;
        for (int i = 0; i < n; ++i) {
            long long w;
            cin >> w;
            total_w += w;
        }
        for (int i = 0; i < n; ++i) {
            long long v;
            cin >> v;
            total_v += v;
        }
        if (total_w <= V) {
            cout << total_v << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}