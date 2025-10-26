#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int res = 0;
		for (int i = 0; i < n / 2; ++i) {
			if (s[i] != s[n - 1 - i]) {
				res++;
			}
		}
		cout << res << '\n';
	}

	return 0;
}
