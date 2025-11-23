#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int length;
        cin >> length;
        int numbers[length];
        for (int i = 0; i < length; i++) {
            cin >> numbers[i];
        }
        int sum = 0;
        for (int i = 0; i < length; i++) {
            int num = numbers[i];
            for (int j = i; j < length; j++) {
                int t = numbers[j];
                if (num > t) ++sum;
            }
        }
        cout << sum << endl;
    }
    return 0;
}