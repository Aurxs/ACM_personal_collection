#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long n;
    int d = 100,temp = 100,idx = 0;
    cin >> n;
    bitset<60> b;
    cout << b.to_ullong() << endl;
    do {
        cin >> d;
        if(d==0) break;
        b[idx] = true;
        if(d>=temp) {
            b[idx-1] = false;
        }
        idx++;
        temp = d;
        cout << b.to_ullong() << endl;
    }while(true);
    return 0;
}