#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string n;
    cin >> n;
    int a = count(n.begin(),n.end(),'0');
    if (a%2) cout << "No";
    else cout << "Yes";

}