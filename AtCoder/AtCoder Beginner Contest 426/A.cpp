#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int s(string a) {
    if (a=="Ocelot") return 1;
    if (a=="Serval") return 2;
    return 3;
}
void solve() {
    string x,y;
    cin >> x >> y;
    if (s(x)>=s(y)) cout << "Yes" << endl;
    else cout << "No" << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}