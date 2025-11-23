#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > adj(n + 1, vector<int>(n + 1, 0));
    adj[1][(n + 1) / 2] = 1;
    int temp_x = 1, temp_y = (n + 1) / 2;
    for (int i = 2; i <= n * n; i++) {
        if (temp_x == 1 && temp_y != n) {
            temp_x = n;
            temp_y++;
        } else if (temp_y == n && temp_x != 1) {
            temp_y = 1;
            temp_x--;
        } else if (temp_x == 1 && temp_y == n) {
            temp_x++;
        } else if (temp_x != 1 && temp_y != n) {
            if (adj[temp_x - 1][temp_y + 1] == 0) {
                temp_x--;
                temp_y++;
            } else {
                temp_x++;
            }
        }
        adj[temp_x][temp_y] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int T;
    // cin >> T;
    // while (T--) {
    //     solve();
    // }
    solve();

    return 0;
}