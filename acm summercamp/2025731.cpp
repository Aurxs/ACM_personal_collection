#include <iostream>

using namespace std;

int main() {
	int a;
	cin >> a;
	while (a--) {
		string s;
		cin >> s;
		if (s.length() == 2)
			cout << "qidong!" << endl;
		else
			cout << "buqidong." << endl;
	}
	cout << "helloworld";

	return 0;
}