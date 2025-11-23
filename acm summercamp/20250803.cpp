#include <iostream>
#include <string>
using namespace std;

int digitalRoot(string num) {
    if (num == "0") {
        return 0;
    }
    int sum;
    do {
        sum = 0;
        for (char c: num) {
            sum += c - '0';
        }
        num = to_string(sum);
    } while (sum >= 10);
    return sum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string N;
        cin >> N;
        cout << digitalRoot(N) << '\n';
    }

    return 0;
}