#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void solve() {
    int n, ans = 0;
    bool flag = true;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (flag) {
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            if (v[i] != 0) {
                l = i;
                for (int j = i; j < n; j++) {
                    if (v[j] == 0) {
                        r = j;
                        break;
                    }
                }
                if (r == -1) r = n;
                break;
            }
        }
        const auto m = min_element(v.begin() + l, v.begin()+r);
        const int a = *m;
        ans += a;
        for (int i = l; i < r; i++) {
            v[i] -= a;
        }
        bool temp = true;
        for (int i = 0; i < n; i++) {
            if (v[i] != 0) temp = false;
        }
        if (temp) {
            flag = false;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}


//AC code
/*
#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
long long ans=0;
int main()
{
cin>>n;
for(int i=1;i<=n;i++)     cin>>a[i];
for(int i=2;i<=n;i++)     if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
cout<<ans+a[1];
return 0;
}
*/