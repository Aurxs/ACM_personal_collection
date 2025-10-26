#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> heights;
    int h;
    while (cin >> h) {
        heights.push_back(h);
    }

    vector<int> dp1(heights.size(), 1);
    int ans1 = 1;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (heights[j] >= heights[i]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
        ans1 = max(ans1, dp1[i]);
    }
    cout << ans1 << endl;

    vector<int> dp2(heights.size(), 1);
    int ans2 = 1;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (heights[j] < heights[i]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
        ans2 = max(ans2, dp2[i]);
    }
    cout << ans2 << endl;

    return 0;
}