#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        unordered_map<long long, int> posts;
        vector<int> x_coords;

        while (n--) {
            int x, y, d;
            cin >> x >> y >> d;
            posts[(long long) x << 32 | (y + 100000)] = d; // y ∈ [-1e5,1e5]
            x_coords.push_back(x);
        }

        sort(x_coords.begin(), x_coords.end());
        x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());

        int sum = 0;
        int x = 0, y = 0;
        size_t idx = 0;

        while (idx < x_coords.size()) {
            if (x == x_coords[idx]) {
                long long key = (long long) x << 32 | (y + 100000);
                if (posts.count(key)) {
                    sum++;
                    y += posts[key];
                    x++;
                    if (idx < x_coords.size() && x == x_coords[idx]) {
                        continue;
                    }
                }
                idx++;
            } else {
                x = x_coords[idx];
            }
        }
        cout << sum << endl;
    }
    return 0;
}